//
//  MonthsWithoutFeeView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import SwiftUI

struct MonthsWithoutFeeView: View {
    
    @StateObject var viewModel: TransactionWorkFlowViewModel
    
    var body: some View {
        VStack {
            Text("Selecciona el número de pagos")
                .padding()
            Spacer()
            List {
                ForEach(viewModel.months, id: \.id) { mvf in
                    Button(action: {
                        viewModel.select(month: mvf)
                    }) {
                        MonthsWithoutFeeCellView(mwf: mvf)
                            .padding(.bottom, 10.0)
                    }
                }
            }
            Spacer()
            if let onePayment = viewModel.onePayment {
                Button(action: {
                    viewModel.onePay()
                }) {
                    MonthsWithoutFeeCellView(
                        mwf: onePayment
                    )
                        .padding()
                }
            }
        }
    }
}

struct MonthsWithoutFeeView_Previews: PreviewProvider {
    static var previews: some View {
        MonthsWithoutFeeView(viewModel: TransactionWorkFlowViewModel())
    }
}
