//
//  TransactionWorkFlowViewModel+KNPaymentDelegate.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 07/12/21.
//

import KNPayment
import KNCore

extension TransactionWorkFlowViewModel: KNPaymentDelegate {
    
    func onPaymentCurrentState(state: KNPaymentState) {
        DispatchQueue.main.async { [weak self] in
            self?.transactionState = state.message
        }
    }
    
    func onRequestTips() {
        DispatchQueue.main.async { [weak self] in
            self?.cleanView()
            self?.showsTipAlert = true
        }
    }
    
    func onPaymentSucess(result: KNPaymentResult) {
        DispatchQueue.main.async { [weak self] in
            self?.cleanView()
            self?.transactionSuccess = result
            self?.transactionResult = ResultViewModel(
                imageName: "success",
                result: "Exito",
                printEnable: true
            )
            self?.showState = false
            self?.transactionFinish = true
        }
    }
    
    func onPaymentError(error: KNPaymentError) {
        DispatchQueue.main.async { [weak self] in
            self?.cleanView()
            self?.transactionSuccess = nil
            if !(self?.alertLauched ?? false) {
                self?.alertLauched.toggle()
                self?.transactionResult = ResultViewModel(
                    imageName: "error",
                    result: "Error",
                    detail: error.errorLocalizedDescription,
                    printEnable: false,
                    errorCode: error.code.string
                )
            }
            self?.showState = false
            self?.transactionFinish = true
        }
    }
    
    func onMonthsAvailable(months: [KNPaymentMonth]) {
        DispatchQueue.main.async { [weak self] in
            self?.internalMonths = months
            self?.months = months.map({ mwfModel -> MWFModel in
                return mwfModel.getKMWFModel()
            })
            self?.cleanView()
            self?.showMonths = true
        }
    }
    
    func onReaderInfo(reader: KNReaderInfo) {
    }
}
