//
//  OTAUpdateViewModel+KNUpdateOtaDelegate.swift
//  KNCoreDemo
//
//  Created by Martín González Escamilla on 12/04/22.
//

import KNPayment
import KNCore

extension OTAUpdateViewModel: KNUpdateOtaDelegate {
    
    public func onUpdateProgress(progress: Int) {
        debugPrint("OTA UPDATING progress:\(progress)")
        DispatchQueue.main.async { [weak self] in
            self?.message = "Actualizando: \(progress)%"
            self?.percent = Float(progress)/100
        }
    }
    
    public func onUpdateSuccess() {
        debugPrint("OTA UPDATE finish")
        PaymentManager.shared.payment.tryReconnect()
        DispatchQueue.main.async { [weak self] in
            self?.message = "Actualización exitosa"
        }
    }
    
    public func onUpdateError(error: KNPaymentError) {
        debugPrint("OTA UPDATE error: \(error.errorLocalizedDescription ?? "")")
        DispatchQueue.main.async { [weak self] in
            self?.message = "Error en la actualización: \(error.errorLocalizedDescription ?? "")"
            self?.hideProgress = true
        }
    }
}
