//
//  KNOperation+Extension.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 13/11/21.
//

import Foundation
import KNCore
import UIKit

extension KNOperation {
    
    func getOperation() -> Operation {
        var color = UIColor(named: "PurpleKonfio")
        if self.total.amount.contains("-") {
            color = UIColor(named: "RedError")
        }
        
        var reference = self.reference.description
        if reference == "" {
            reference = "Sin Referencia"
        }
        
        return Operation(
            id: self.transaction,
            reference: reference,
            ammount: self.total.amount,
            date: self.timestamp,
            canceled: self.hasDevolution,
            color: color ?? .black
        )
    }
}
