//
//  MWFModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import Foundation
import KNCore

struct MWFModel {
    
    let id: Int
    let numMonths: String
    let youGetAmount: String
    let paymentPerMount: String
    let commissionPayment: String
}

extension KNPaymentMonth {
    
    func getKMWFModel() -> MWFModel{
        return MWFModel(
            id: self.months,
            numMonths: "\(self.months) meses",
            youGetAmount: "",
            paymentPerMount: "Pagos de $\(self.amount)",
            commissionPayment: "\(self.rate)% de comisión + IVA"
        )
    }
}
