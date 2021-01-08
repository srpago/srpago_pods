
Pod::Spec.new do |sdk|

  sdk.name         = "SrPagoSDK"
  sdk.version      = "0.0.6"
  sdk.summary      = "SDK de Señor pago"
  sdk.description  = <<-DESC
    SDK de Señor pago para iOS
                   DESC

  sdk.homepage     = "https://srpago.com"

  sdk.license      = { :type => "MIT", :text => "© 2020 SrPago" }
  
  sdk.author             = { "Ricardo Hernandez" => "rhernandez@srpago.com" }
  sdk.platform     = :ios, "9.0"

  sdk.source       = { :git => "https://github.com/srpago/srpago_pods.git",:tag => 'v0.0.6'}
  sdk.default_subspec = 'Core'
  
    sdk.subspec 'Core' do |core|
        core.vendored_frameworks = "SrPagoSDK.framework"
    end

    sdk.subspec 'Ecommerce' do |ecommerce|
        ecommerce.vendored_frameworks = "EcommerceModule.framework"
        ecommerce.dependency 'SrPagoSDK/Core'
    end
    
    sdk.subspec 'Reader' do |reader|
        reader.vendored_frameworks = "ReaderModule.framework"
        reader.dependency 'SrPagoSDK/Core'
    end
    

end
