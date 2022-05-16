//
//  PaymentView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 12/11/21.
//

import SwiftUI
import Combine

struct PaymentView: View {
    
    @StateObject var viewModel: PaymentViewModel = PaymentViewModel()
    
    @State private var amountSale: String = "0"
    @State private var descriptionSale: String = ""
    @State private var selection: String? = nil
    @State private var value: Double = 0
    
    var body: some View {
        VStack {
            NavigationLink(
                destination: ListDevicesUIView(),
                tag: "Link",
                selection: $selection
            ) { EmptyView() }
            NavigationLink(
                destination: TransactionWorkFlowView(
                    amount: amountSale,
                    reference: descriptionSale
                ),
                tag: "Pay",
                selection: $selection
            ) { EmptyView() }
            Text("Realizar un cargo")
                .font(.title)
                .foregroundColor(.black)
            Spacer()
            VStack {
                Text("Monto a cobrar")
                    .frame(width: 250, height: 40, alignment: .leading)
                CurrencyTextField(value: $value,
                                  amountSale: $amountSale)
                    .keyboardType(.decimalPad)
                    .frame(width: 250, height: 40, alignment: .center)
            }
            Spacer()
            VStack {
                Text("Descripción de la venta")
                    .frame(width: 250, height: 40, alignment: .leading)
                TextField("Descripción", text: $descriptionSale)
                    .onReceive(Just(descriptionSale)) { _ in limitText(&descriptionSale, 20) }
                    .frame(width: 250, height: 40, alignment: .center)
            }
            Spacer()
            Button(action: {
                hideKeyboard()
                if viewModel.isReaderVinculated() {
                    selection = "Pay"
                } else {
                    selection = "Link"
                }
            }) {
                Text("Cobrar")
                    .foregroundColor(.white)
                    .frame(width: 250, height: 50, alignment: .center)
                    .background(Color("PurpleKonfio"))
            }
        }
        .onAppear {
            amountSale = "0"
            descriptionSale = ""
            value = 0
        }
    }
}

struct PaymentView_Previews: PreviewProvider {
    static var previews: some View {
        PaymentView()
    }
}
