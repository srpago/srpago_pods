//
//  PrinterListView.swift
//  KNCoreDemo
//
//  Created by Luis Genaro Arvizu Vega on 27/10/21.
//

import SwiftUI
import KNCore

struct PrinterListView: View {
    
    @StateObject var viewModel: PrinterListViewModel
    
    @State var isWifiPrinter: Bool = false
    
    var body: some View {
        NavigationView {
            List {
                HStack {
                    Spacer()
                    Toggle("Wifi Printer", isOn: $isWifiPrinter)
                }
                if isWifiPrinter {
                    Button("Print") {
                        viewModel.wifiPrint()
                    }
                } else {
                    ForEach(viewModel.printers) { printer in
                        Button("\(printer.name)") {
                            viewModel.connect(printer: printer)
                        }
                    }
                }
            }
            .navigationBarTitle (Text("Selecciona una impresora"), displayMode: .inline)
        }
        .navigationViewStyle(StackNavigationViewStyle())
    }
}

struct PrinterListView_Previews: PreviewProvider {
    static var previews: some View {
        let viewModel = PrinterListViewModel(ticket: PrinterModel.getMockReceipt())
        PrinterListView(viewModel: viewModel)
    }
}
