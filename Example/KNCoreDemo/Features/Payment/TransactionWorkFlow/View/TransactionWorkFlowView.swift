//
//  TransactionWorkFlowView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import SwiftUI
import MessageUI

struct TransactionWorkFlowView: View {
    
    @StateObject var viewModel: TransactionWorkFlowViewModel = TransactionWorkFlowViewModel()
    @State private var showsEmailAlert = false
    @State var result: Result<MFMailComposeResult, Error>? = nil
    @Environment(\.presentationMode) var presentation
    let amount: String
    let reference: String
    
    var body: some View {
        VStack {
            NavigationLink(
                destination: PrinterListView(
                    viewModel: PrinterListViewModel(
                        ticket: viewModel.ticketToPrint ?? PrinterModel.getMockReceipt()
                    )
                ),
                isActive: $viewModel.showPrinter
            ) {
                EmptyView()
            }
            Text("Estado de transacción")
                .font(.title)
                .padding(20)
                .foregroundColor(.black)
            ZStack {
                if viewModel.showState {
                    VStack {
                        Spacer()
                        Text(viewModel.transactionState)
                        Spacer()
                    }
                }
                if viewModel.showMonths {
                    VStack {
                        MonthsWithoutFeeView(viewModel: viewModel)
                        Button(action: {
                            presentation.wrappedValue.dismiss()
                        }) {
                            Text("Terminar")
                                .foregroundColor(.white)
                                .frame(width: 250, height: 50, alignment: .center)
                                .background(Color("PurpleKonfio"))
                        }
                        .padding(5)
                    }
                }
                if viewModel.transactionFinish {
                    VStack {
                        TransactionResultView(viewModel: viewModel)
                        if !viewModel.webServiceRequest.isEmpty {
                            Button(action: {
                                showsEmailAlert = true
                            }) {
                                Text("QA Enviar transacción")
                                    .foregroundColor(.white)
                                    .frame(width: 250, height: 50, alignment: .center)
                                    .background(Color("PurpleKonfio"))
                            }
                            .padding(5)
                        }
                        Button(action: {
                            presentation.wrappedValue.dismiss()
                        }) {
                            Text("Finalizar")
                                .foregroundColor(.white)
                                .frame(width: 250, height: 50, alignment: .center)
                                .background(Color("PurpleKonfio"))
                        }
                        .padding(5)
                        Spacer()
                    }
                }
                if $viewModel.showsTipAlert.wrappedValue {
                    ZStack {
                        Spacer()
                        TransactionTipView(viewModel: viewModel)
                        Spacer()
                    }
                }
            }
        }
        .navigationBarHidden(true)
        .sheet(isPresented: $showsEmailAlert) {
            MailView(isShowing: $showsEmailAlert,
                     message: $viewModel.webServiceRequest,
                     result: $result)
        }
        .onLoad {
            viewModel.startTransaction(amount: amount, reference: reference)
        }
    }
}

struct TransactionWorkFlowView_Previews: PreviewProvider {
    static var previews: some View {
        TransactionWorkFlowView(
            amount: "123.45",
            reference: "Prueba"
        )
    }
}
