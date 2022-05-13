//
//  OTAUpdateViewModel.swift
//  KNCoreDemo
//
//  Created by Martín González Escamilla on 12/04/22.
//

import Foundation
import KNPayment
import KNCore

class OTAUpdateViewModel: ObservableObject {
    
    var paymentManager: KNPayment?
    
    @Published var message: String = ""
    @Published var percent: Float = 0.0
    @Published var hideProgress = true
    @Published var hideDownloadButton = true
    
    init() {
        paymentManager = PaymentManager.shared.payment
        checkOta()
    }
    
    func checkOta() {
        paymentManager?.checkOtaUpdate(needUpdate: { [weak self] isUpdateNeeded in
            DispatchQueue.main.async { [weak self] in
                if isUpdateNeeded == true {
                    self?.message = "Hay una actualización disponible"
                    self?.hideDownloadButton = false
                } else {
                    self?.hideProgress = true
                    self?.message = "No hay actualizaciones disponibles"
                }
            }
        })
    }
    
    func startOta() {
        DispatchQueue.main.async { [weak self] in
            self?.message = ""
            self?.hideProgress = false
            self?.hideDownloadButton = true
            guard let self = self else {
                return
            }
            self.paymentManager?.startOtaUpdate(delegate: self)
        }
    }
}
