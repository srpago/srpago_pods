//
//  ListDevicesViewModel.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 14/10/21.
//

import Foundation
import KNPayment
import KNCore

class ListDevicesViewModel: ObservableObject {
    
    @Published var devices: [KNBluetoothReader]
    @Published var status: String
    @Published var readerLinked: String
    @Published var isLoading: Bool = false
    @Published var alert: AlertBody?
    var readerName: String
    var view: ListDevicesUIView?
    
    internal var paymentManager: KNPayment?
    
    init() {
        devices = []
        status = ""
        readerName = ""
        readerLinked = ""
        paymentManager = PaymentManager.shared.payment
        paymentManager?.configBluetoothReaderState(delegate: self)
    }
    
    func getReaderInfo() {
        paymentManager?.getReader(info: { [weak self] readerInfo in
            self?.readerLinked = readerInfo.serialNumber
        }, error: { _ in })
    }
    
    func startScan(_ view: ListDevicesUIView?) {
        self.view = view
        paymentManager?.searchDevices(nil)
    }
    
    func stopScan() {
        paymentManager?.stopSearchDevices()
    }
    
    func connectWith(reader: KNBluetoothReader) {
        readerName = reader.device.name
        paymentManager?.connectReader(reader)
    }
}
