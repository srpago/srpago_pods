//
//  OperationsView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 12/11/21.
//

import SwiftUI

struct OperationsView: View {
    
    @StateObject var listViewModel: OperationsViewModel = OperationsViewModel()
    @State private var showingOptions = false
    @State private var showsSMSAlert = false
    @State private var showsEmailAlert = false
    @State private var actionsSheets: [ActionSheet.Button] = []
    
    var body: some View {
        VStack(content: {
            NavigationLink(
                destination: PrinterListView(
                    viewModel: PrinterListViewModel(
                        ticket: listViewModel.ticketToPrint ?? PrinterModel.getMockReceipt()
                    )
                ),
                isActive: $listViewModel.showPrinter
            ) {
                EmptyView()
            }
            Text("Transacciones")
                .font(.title)
                .foregroundColor(.black)
            Spacer()
                .frame(height: 20)
            List {
                ForEach(listViewModel.operations, id: \.id) { operation in
                    Button(action: {
                        showingOptions = true
                        listViewModel.select(operation: operation)
                        if operation.canceled || operation.color == UIColor(named: "RedError") {
                            self.actionsSheets = [
                            .default(Text("Imprimir")) {
                                listViewModel.printOperation()
                            },
                            .default(Text("Enviar por email")) {
                                showsEmailAlert = true
                            },
                            .default(Text("Enviar por SMS")) {
                                showsSMSAlert = true
                            },
                            .cancel(Text("Cancelar"))
                            ]
                        } else {
                            self.actionsSheets = [
                            .default(Text("Imprimir")) {
                                listViewModel.printOperation()
                            },
                            .default(Text("Enviar por email")) {
                                showsEmailAlert = true
                            },
                            .default(Text("Enviar por SMS")) {
                                showsSMSAlert = true
                            },
                            .destructive(Text("Hacer devolución")) {
                                listViewModel.deleteOperation()
                            },
                            .cancel(Text("Cancelar"))
                            ]
                        }
                    }) {
                        OperationCellView(operation: operation)
                    }
                    .actionSheet(isPresented: $showingOptions) {
                        ActionSheet(
                            title: Text("Selecciona una acción"),
                            buttons: actionsSheets
                        )
                    }
                }
            }
            Spacer()
        })
            .alert(item: $listViewModel.alert) { result in
                Alert(
                    title: Text(result.title),
                    message: Text(result.body),
                    dismissButton: .default(
                        Text(result.primaryButtonMessage),
                        action: result.primaryAction
                    )
                )
            }
            .alert(isPresented: $showsEmailAlert, TextAlert(
                title: "Agrega tu correo",
                placeholder: "example@domain.com",
                accept: "Enviar",
                keyboardType: .emailAddress,
                action: {
                    if let email = $0 {
                        listViewModel.sendOperation(email: email)
                    }
                }))
            .alert(isPresented: $showsSMSAlert, TextAlert(
                title: "Agrega tu telefono",
                placeholder: "Número de teléfono",
                accept: "Enviar",
                keyboardType: .phonePad,
                action: {
                    if let sms = $0 {
                        listViewModel.sendOperation(sms: sms)
                    }
                }))
            .onAppear {
                listViewModel.getOperations()
            }
    }
}

struct OperationsView_Previews: PreviewProvider {
    static var previews: some View {
        OperationsView()
    }
}
