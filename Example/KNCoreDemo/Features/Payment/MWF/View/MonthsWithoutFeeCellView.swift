//
//  MonthsWithoutFeeCellView.swift
//  KNCoreDemo
//
//  Created by Fernando Bustos on 15/11/21.
//

import SwiftUI

struct MonthsWithoutFeeCellView: View {
    
    var mwf: MWFModel
    
    var body: some View {
        HStack {
            VStack(alignment: .leading) {
                Text(mwf.numMonths)
                    .fontWeight(.semibold)
                    .foregroundColor(.black)
                Spacer()
                Text(mwf.commissionPayment)
                    .font(.caption)
                    .foregroundColor(.gray)
                    .fixedSize(horizontal: false, vertical: true)
            }
            Spacer()
            VStack(alignment: .leading) {
                Text(mwf.paymentPerMount)
                    .font(.footnote)
                    .foregroundColor(Color("PurpleKonfio"))
                Spacer()
                Text(mwf.youGetAmount)
                    .font(.footnote)
                    .fontWeight(.medium)
                    .foregroundColor(.black)
            }
        }
        .frame(height: 45.0)
        .padding(8)
        .cornerRadius(15)
    }
}

struct MonthsWithoutFeeCellView_Previews: PreviewProvider {
    static var previews: some View {
        let mwf = MWFModel(
            id: 3,
            numMonths: "3 meses",
            youGetAmount: "Tu obtienes $567.89",
            paymentPerMount: "Pagos de $123.45",
            commissionPayment: "6.84% de comisión + IVA \n este texto solo es de prueba"
        )
        Group {
            MonthsWithoutFeeCellView(mwf: mwf)
                
        }
        .previewLayout(/*@START_MENU_TOKEN@*/.sizeThatFits/*@END_MENU_TOKEN@*/)
        .previewDevice("iPhone SE (2nd generation)")
    }
}
