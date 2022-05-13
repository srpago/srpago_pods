//
//  ListDevicesViewModel+KNBluetoothReaderDelegate.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 05/11/21.
//

import Foundation
import KNPayment
import KNCore
import UIKit

extension ListDevicesViewModel: KNBluetoothReaderDelegate {
    
    func onListReadersFound(devices: [KNBluetoothReader]) {
        self.devices = devices
    }
    
    func bluetooth(state: KNBluetoothState) {
        switch state {
        case .bluetoothOff:
            status = "Bluetooth Off"
        case .bluetoothOn:
            status = "Bluetooth On"
            startScan(view)
        case .unauthorizedPermissions:
            status = "Permission's bluetooth unauthorized"
            alert = AlertBody(
                id: ObjectIdentifier(NSObject()),
                title: "Error",
                body: "No se han dado permisos de bluetooth",
                primaryButtonMessage: "Ir a configuración",
                primaryAction: {
                    if let url = URL(string: "App-Prefs:root=Bluetooth"){
                        UIApplication.shared.open(url, options: [:], completionHandler: nil)
                    }
                },
                secondaryButtonMessage: "Cancelar",
                secondaryAction: { }
            )
        case .denied:
            status = "Permission's bluetooth denied"
        case .unsupported:
            status = "Bluetooth unsupported"
        case .unknow:
            status = "We have a problem with your bluetooth, please verify his correct working"
        case .resetting:
            status = "Bluetooth resetting"
            startScan(view)
        }
    }
    
    func onReaderState(state: KNReaderState) {
        DispatchQueue.main.async { [weak self] in
            self?.status = state.string
            switch state {
            case .onBTConnected:
                self?.readerLinked = self?.readerName ?? ""
                self?.isLoading = false
                self?.alert = AlertBody(
                    id: ObjectIdentifier(NSObject()),
                    title: "Exito",
                    body: "Lector conectado \(self?.readerName ?? "")",
                    primaryButtonMessage: "Aceptar",
                    primaryAction: {
                        self?.view?.presentationMode.wrappedValue.dismiss()
                    }
                )
                self?.getReaderInfo()
            case .onBtDisconnected:
                self?.isLoading = false
            case .onPowerButtonPressed:
                self?.isLoading = false
            case .onUnkwnowReader:
                self?.isLoading = false
            case .onBTPairing:
                self?.isLoading = true
            case .onErrorPairing:
                self?.isLoading = false
                self?.alert = AlertBody(
                    id: ObjectIdentifier(NSObject()),
                    title: "Error",
                    body: "No se pudo conectar con el lector \(self?.readerName ?? "")",
                    primaryButtonMessage: "Aceptar"
                )
            }
        }
    }
}
