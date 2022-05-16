//
//  PaymentManager.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 18/03/22.
//

import KNPayment

public final class PaymentManager {
    
    public let payment: KNPayment
    
    public static let shared = PaymentManager()
    
    private init() {
        payment = KNPayment()
    }
}
