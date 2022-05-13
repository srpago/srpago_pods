//
//  OperationsViewModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 12/11/21.
//

import Foundation
import KNPayment
import KNCore

class OperationsViewModel: ObservableObject {
    
    @Published var operations: [Operation] = []
    @Published var alert: AlertBody?
    @Published var showPrinter = false
    private var operationToSend: Operation?
    private var operationsFullInfo: [KNOperation] = []
    var ticketToPrint: KNRecipe?
    
    func getOperations() {
        operations = []
        PaymentManager.shared.payment.getTransactions(offset: 0, limit: 100) { result in
            if let operationsResult = result {
                DispatchQueue.main.async { [weak self] in
                    self?.operationsFullInfo = operationsResult
                    self?.operations = operationsResult.map({ operation -> Operation in
                        return operation.getOperation()
                    })
                }
            }
        }
    }
    
    func deleteOperation() {
        PaymentManager.shared.payment.makeRefund(transactionId: operationToSend?.id ?? "") { result in
            DispatchQueue.main.async { [weak self] in
                if let _ = result {
                    self?.alert = AlertBody(
                        id: ObjectIdentifier(NSObject()),
                        title: "Exito",
                        body: "Transacción devuelta exitosamente",
                        primaryButtonMessage: "Aceptar",
                        primaryAction: {
                            self?.getOperations()
                        }
                    )
                } else {
                    self?.alert = AlertBody(
                        id: ObjectIdentifier(NSObject()),
                        title: "Error",
                        body: "Hubo un problema para devolver la transacción, verifica que la transacción se haya realizado el mismo día",
                        primaryButtonMessage: "Aceptar"
                    )
                }
            }
        }
    }
    
    func printOperation() {
        let filtered = operationsFullInfo.filter { filter in
            return filter.transaction == operationToSend?.id
        }
        if let first = filtered.first {
            PaymentManager.shared.payment.getTicketFrom(operation: first) { [weak self] result in
                DispatchQueue.main.async { [self] in
                    switch result {
                    case .success(let recipe):
                        self?.ticketToPrint = recipe
                        self?.showPrinter = true
                    case .failure(let error):
                        self?.alert = AlertBody(
                            id: ObjectIdentifier(NSObject()),
                            title: "Error",
                            body: error.errorLocalizedDescription ?? error.localizedDescription,
                            primaryButtonMessage: "Aceptar"
                        )
                    }
                }
            }
        }
    }
    
    func select(operation: Operation) {
        operationToSend = operation
    }
    
    func sendOperation(email: String) {
        PaymentManager.shared.payment.sendTicketBy(transactionId: operationToSend?.id ?? "", type: .email, destination: email) { [weak self] result in
            DispatchQueue.main.async { [weak self] in
                if result {
                    self?.alert = AlertBody(
                        id: ObjectIdentifier(NSObject()),
                        title: "Exito",
                        body: "Ticket enviado",
                        primaryButtonMessage: "Aceptar"
                    )
                } else {
                    self?.alert = AlertBody(
                        id: ObjectIdentifier(NSObject()),
                        title: "Error",
                        body: "Hubo un problema para enviar la transacción, verifica el correo ingresado",
                        primaryButtonMessage: "Aceptar"
                    )
                }
            }
        }
    }
    
    func sendOperation(sms: String) {
        PaymentManager.shared.payment.sendTicketBy(transactionId: operationToSend?.id ?? "", type: .sms, destination: sms) { [weak self] result in
            DispatchQueue.main.async { [weak self] in
                if result {
                    self?.alert = AlertBody(
                        id: ObjectIdentifier(NSObject()),
                        title: "Exito",
                        body: "Ticket enviado",
                        primaryButtonMessage: "Aceptar"
                    )
                } else {
                    self?.alert = AlertBody(
                        id: ObjectIdentifier(NSObject()),
                        title: "Error",
                        body: "Hubo un problema para devolver la transacción, verifica el sms ingresado",
                        primaryButtonMessage: "Aceptar"
                    )
                }
            }
        }
    }
}
