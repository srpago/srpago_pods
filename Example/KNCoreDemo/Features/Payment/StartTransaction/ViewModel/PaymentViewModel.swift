//
//  PaymentViewModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 16/11/21.
//

import Foundation
import KNPayment

class PaymentViewModel: ObservableObject {
    
    func isReaderVinculated() -> Bool {
        return PaymentManager.shared.payment.validateConnection()
    }
}

extension String {
    func currencyFormat() -> String {
        let formatter = NumberFormatter()
        formatter.numberStyle = .currencyAccounting
        formatter.currencySymbol = "$"
        formatter.maximumIntegerDigits = 7
        formatter.maximumFractionDigits = 2
        formatter.minimumFractionDigits = 2
        formatter.isLenient = true
        formatter.locale = .current
        formatter.decimalSeparator = "."
        formatter.groupingSeparator = ","
        formatter.groupingSize = 3
        formatter.usesGroupingSeparator = true
        formatter.numberStyle = .decimal
        
        var amount = self
        if let regex = try? NSRegularExpression(pattern: "[^0-9]", options: .caseInsensitive) {
            amount = regex.stringByReplacingMatches(in: amount, options: NSRegularExpression.MatchingOptions(rawValue: 0), range: NSMakeRange(0, count), withTemplate: "")
        }
        
        let double = (amount as NSString).doubleValue
        let number: NSNumber = NSNumber(value: (double / 100))
        guard number != 0 as NSNumber else {
            return ""
        }
        return formatter.string(from: number) ?? ""
    }
}
