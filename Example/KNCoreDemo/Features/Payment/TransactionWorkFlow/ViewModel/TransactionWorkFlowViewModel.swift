//
//  TransactionWorkFlowViewModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import Foundation
import KNPayment
import KNCore

class TransactionWorkFlowViewModel: ObservableObject {
    
    @Published var months: [MWFModel] = []
    @Published var onePayment: MWFModel? = nil
    @Published var transactionResult: ResultViewModel? = nil
    @Published var alert: AlertBody?
    
    @Published var showState = true
    @Published var showsTipAlert = false
    @Published var showMonths: Bool = false
    @Published var showPrinter = false
    @Published var transactionFinish: Bool = false
    @Published var transactionState: String = ""
    @Published var webServiceRequest: String = ""
    
    var ticketToPrint: KNRecipe?
    var paymentManager: KNPayment?
    var internalMonths: [KNPaymentMonth] = []
    var transactionSuccess: KNPaymentResult?
    var totalAmount: Float = 0.0
    var alertLauched = false
    
    init() {
        paymentManager = PaymentManager.shared.payment
        webServiceRequest = ""
    }
    
    func cleanView() {
        showState = true
        showsTipAlert = false
        showMonths = false
        transactionFinish = false
    }
    
    func startTransaction(amount: String, reference: String) {
        let amountNumFormat = amount.replacingOccurrences(of: ",", with: ".")
        debugPrint("Start transaction with amount: \(amountNumFormat) reference \(reference)")
        transactionSuccess = nil
        alertLauched = false
        webServiceRequest = ""
        if let amountFloat = Float(amount) {
            totalAmount = amountFloat
        } else {
            DispatchQueue.main.async { [weak self] in
                self?.onPaymentError(error: KNPaymentError(type: .invalidPaymentError, description: "Formato de pago inválido"))
            return
            }
        }
        paymentManager?.makePayment(amount: amountNumFormat, reference: reference, delegate: self)
    }
    
    func add(tip: String) {
        var tipNumFormat = tip.replacingOccurrences(of: ",", with: ".")
        if tipNumFormat.count == 0 {
            tipNumFormat = "0"
        }
        if let amount = Float(tipNumFormat) {
            paymentManager?.setTip(amount)
            totalAmount += amount
        } else {
            DispatchQueue.main.async { [weak self] in
                self?.onPaymentError(error: KNPaymentError(type: .invalidPaymentError, description: "Formato de propina inválido"))
            }
            return
        }
        onePayment = MWFModel(
            id: 1,
            numMonths: "Pago de contado",
            youGetAmount: "",
            paymentPerMount: getAmount(totalAmount),
            commissionPayment: ""
        )
    }
    
    func select(month: MWFModel) {
        if let selectedMonth = internalMonths.first(where: {$0.months == month.id}) {
            paymentManager?.selectMonth(selectedMonth)
        } else {
            paymentManager?.selectPayInOneExibition()
        }
        cleanView()
    }
    
    func onePay(){
        paymentManager?.selectPayInOneExibition()
        cleanView()
    }
    
    func printTransaction() {
        if let transaction = transactionSuccess {
            PaymentManager.shared.payment.getTicketFrom(transaction: transaction) { [weak self] result in
                DispatchQueue.main.async { [self] in
                    switch result {
                    case .success(let recipe):
                        self?.ticketToPrint = recipe
                        self?.showPrinter = true
                    case .failure(let error):
                        self?.alert = AlertBody(
                            id: ObjectIdentifier(NSObject()),
                            title: "Error",
                            body:  error.errorLocalizedDescription ?? error.localizedDescription,
                            primaryButtonMessage: "Aceptar"
                        )
                    }
                    
                }
            }
        }
    }
    
    func sendOperation(email: String) {
        guard let token = transactionSuccess?.transactionId else {
            return
        }
        PaymentManager.shared.payment.sendTicketBy(transactionId: token, type: .email, destination: email) { [weak self] result in
            DispatchQueue.main.async { [self] in
                var messageTitle = "Error"
                var messageBody = "Hubo un problema para enviar la transacción, verifica el correo ingresado"
                if result {
                    messageTitle = "Exito"
                    messageBody = "Recibo enviado correctamente"
                }
                
                self?.alert = AlertBody(
                    id: ObjectIdentifier(NSObject()),
                    title: messageTitle,
                    body: messageBody,
                    primaryButtonMessage: "Aceptar"
                )
            }
        }
    }
    
    func sendOperation(sms: String) {
        guard let token = transactionSuccess?.transactionId else {
            return
        }
        PaymentManager.shared.payment.sendTicketBy(transactionId: token, type: .sms, destination: sms) { [weak self] result in
            DispatchQueue.main.async { [self] in
                var messageTitle = "Error"
                var messageBody = "Hubo un problema para devolver la transacción, verifica el sms ingresado"
                if result {
                    messageTitle = "Exito"
                    messageBody = "Recibo enviado correctamente"
                }
                
                self?.alert = AlertBody(
                    id: ObjectIdentifier(NSObject()),
                    title: messageTitle,
                    body: messageBody,
                    primaryButtonMessage: "Aceptar"
                )
            }
        }
    }
    
    func cancelTransaction() {
        cleanView()
    }
    
    private func getAmount(_ amount: Float) -> String {
        let total = String(format: "%.2f", amount)
        return "$\(total)"
    }
}
