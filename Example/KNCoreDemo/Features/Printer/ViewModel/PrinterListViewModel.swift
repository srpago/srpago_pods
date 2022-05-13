//
//  PrinterListViewModel.swift
//  KNCoreDemo
//
//  Created by Luis Genaro Arvizu Vega on 27/10/21.
//

import Foundation
import KNPayment
import KNCore

class PrinterListViewModel: ObservableObject {
    
    @Published var printers: [KNPrinter] = []
    @Published var isConnected: Bool = false
    
    private var paymentManager: KNPayment?
    var ticketToPrint: KNRecipe
    
    init(ticket: KNRecipe) {
        ticketToPrint = ticket
        paymentManager = PaymentManager.shared.payment
        paymentManager?.configPrinter(delegate: self)
    }
    
    func connect(printer: KNPrinter) {
        _ = paymentManager?.connectPrinter(printer: printer)
    }
       
    func wifiPrint() {
        guard let data: [Data] = paymentManager?.createWifi(recipe: ticketToPrint) else {
            return
        }
        
        paymentManager?.printRecipeByWifi(data: data)           
    }
        
    private func searchPrinter(printer: KNPrinter) -> KNPrinter? {
        printers.first(where: {$0.bluetoothUUID == printer.bluetoothUUID})
    }
    
    private func bluetoothPrinter() {
        guard let data: [Data] = paymentManager?.createBluetooth(recipe: ticketToPrint) else {
            return
        }
        _ = paymentManager?.printRecipeByBluetooth(data: data)
    }
}

extension PrinterListViewModel: KNPrinterDelegate {
    
    func printer(state: KNBluetoothState) {
        switch state {
        case .bluetoothOff:
            break
        case .bluetoothOn:
            paymentManager?.searchPrinters(nil)
        case .unauthorizedPermissions:
            break
        case .denied:
            break
        case .unsupported:
            break
        case .unknow:
            break
        case .resetting:
            paymentManager?.searchPrinters(nil)
        }
    }
    
    func printer(printers: [KNPrinter]) {
        self.printers = printers
    }
    
    func printer(_ printer: KNPrinter, connected: Bool) {
        guard var currentPrinter: KNPrinter = searchPrinter(printer: printer) else {
            return
        }
        currentPrinter.isConnected = true
        isConnected = true
        
        bluetoothPrinter()
    }
    
    func printer(printerProgress: KNPrinterProgress) {
        switch printerProgress {
        case .started:
            debugPrint("Print finished")
        case .inProgress:
            debugPrint("In Progress")
        case .finished:
            debugPrint("Finished")
        case .interrumped:
            debugPrint("Interrumped")
        }
    }        
}
