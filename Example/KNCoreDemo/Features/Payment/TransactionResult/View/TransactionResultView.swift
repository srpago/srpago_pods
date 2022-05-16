//
//  TransactionResultView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import SwiftUI

struct TransactionResultView: View {
    
    @StateObject var viewModel: TransactionWorkFlowViewModel
    @State private var showingOptions = false
    @State private var showsSMSAlert = false
    @State private var showsEmailAlert = false
    
    var body: some View {
        VStack{
            Image(viewModel.transactionResult?.imageName ?? "error", bundle: nil)
                .resizable()
                .aspectRatio(contentMode: .fit)
                .frame(width: 200, height: 130, alignment: .center)
                .padding()
            Text(viewModel.transactionResult?.result ?? "")
                .fontWeight(.semibold)
                .fixedSize(horizontal: false, vertical: true)
                .padding()
            Text(viewModel.transactionResult?.detail ?? "")
                .fixedSize(horizontal: false, vertical: true)
                .padding(20)
            Spacer()
                .frame(height: 20)
            if let errorCode = viewModel.transactionResult?.errorCode {
                HStack {
                    Text("Code: \(errorCode)")
                    Spacer()
                }
                .padding(5)
            }
            if viewModel.transactionResult?.printEnable ?? false {
                Button(action: {
                    showingOptions = true
                }) {
                    Text("Enviar")
                        .foregroundColor(.white)
                        .frame(width: 250, height: 50, alignment: .center)
                        .background(Color("PurpleKonfio"))
                }
                .actionSheet(isPresented: $showingOptions) {
                    ActionSheet(
                        title: Text("Selecciona una acción"),
                        buttons: [
                            .default(Text("Imprimir")) {
                                viewModel.printTransaction()
                            },
                            .default(Text("Enviar por email")) {
                                showsEmailAlert = true
                            },
                            .default(Text("Enviar por SMS")) {
                                showsSMSAlert = true
                            },
                            .cancel(Text("Cancelar"))
                        ]
                    )
                }
            }
        }
        .alert(item: $viewModel.alert) { result in
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
                viewModel.sendOperation(email: email)
            }
        }))
        .alert(isPresented: $showsSMSAlert, TextAlert(
            title: "Agrega tu telefono",
            placeholder: "Número de teléfono",
            accept: "Enviar",
            keyboardType: .phonePad,
            action: {
            if let sms = $0 {
                viewModel.sendOperation(sms: sms)
            }
        }))
    }
}

struct TransactionResultView_Previews: PreviewProvider {
    static var previews: some View {
        TransactionResultView(viewModel: TransactionWorkFlowViewModel())
    }
}
