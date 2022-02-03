Pod::Spec.new do |sdk|

  sdk.name         = "SrPagoSDK"
  sdk.version      = "1.2.0"
  sdk.summary      = "SDK de Sr.pago"
  sdk.description  = <<-DESC
    SDK de Señor pago para iOS
                   DESC

  sdk.homepage     = "https://srpago.com"

  sdk.license      = { :type => "MIT", :text => "© 2022 SrPago" }

  sdk.authors      = {
    'Fernando Bustos' => 'luis.bustos@konfio.mx',
    'Jorge Mejia' => 'jmejiah@srpago.com',
    'Genaro Arvizu' => 'lgarvizuv@srpago.com',
    'Martín Gonzales' => 'mgonzaleze@srpago.com'
   }
  sdk.platform     = :ios, "11.0"

  sdk.source       = { :git => "https://github.com/srpago/srpago_pods.git", :branch => 'feature/PaymentsV2'}
  #sdk.vendored_frameworks = 'KNPaymentFramework.xcframework'
  sdk.frameworks = 'KNPaymentFramework'
end
