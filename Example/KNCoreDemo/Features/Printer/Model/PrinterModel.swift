//
//  PrinterModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 10/12/21.
//

import Foundation
import KNCore

struct PrinterModel {
    
    static func getMockReceipt() -> KNRecipe{
        return KNRecipe(logo: nil,
                        businessName: "BusinessName",
                        address: "Mexico, Mexico, 12345, MX",
                        phone: "0123456789",
                        date: "2018-10-25T12:48:37-05:00",
                        aid: "123456789",
                        arqc: "123456789",
                        authMethod: .nip,
                        msiMonths: "",
                        cardNumber: "5629",
                        reference: "asdfasdf",
                        cardHolder: "Genaro Arvizu",
                        cardType: .amex,
                        afiliation: "7140215",
                        tipAmount: "5",
                        amount: "9999",
                        totalAmount: "10004",
                        signature: nil,
                        authNumber: "123456789",
                        isOriginalTicket: true,
                        cardMethodName: "Bank",
                        cardMethodType: "Credit"
        )
    }
}
