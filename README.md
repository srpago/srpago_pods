# SrPago-SDK

Modules:
 - EcommerceModule
 - ReaderModule
 - SrPagoSDK

## Requirements

- Xcode 13
- Swift 5
- Minimum iOS 11 version supported
- Cocoapods
- iPhones and iPads supported

## Frameworks

| Pod name              | Version |
| --------------------- | ------- |
| lottie-ios            | 3.2.3   |

# ChangeLog

## [1.3.0] 2022-05-05

## Added
- OTA update in background

## [1.2.2] 2022-03-02

## Added
- OTA update supported in BBPOS readers

## [1.2.1] 2022-02-22

## Removed
- Unusable params in settings request

## [1.2.0] 2022-02-01

## Added
- New environments support
- Battery report was improved

## [1.1.9] 2022-01-06

### Added
- PAX vinculated info was improved

### Changed
- Support for Xcode 13 and iOS 15
- Minimum iOS version was changed to 11

## [1.1.8] 2021-09-11

### Added
- Adding MSI value on Receipt
- Refound consume service

### Changed
- Brand card BBPOSManager
- Update headers according to environment
- Reader time transaction was changed from 120 seconds to 30 from BBPOS Reader

### Fixed
- Logging the 'SUCCESS' status on transacation
- Null value crash in PAX print
- Validating empty fields of address to avoid show wrong string address

## [1.1.7] 2021-08-31

### Added
- Transaction web service, return transactions values
- Add ISO field in Bluetooth and WIFI ticket
- Reference field is now limited to 20 characters
- Headers for each web service
- Decrypt Method for base url

### Fixed
- Generic Printer works again

### Removed
- Old Readers were removed

## [1.1.6] 2021-07-15

### Added

- Master Card **Sonicbrand** Sound
- Unit Tests

## Removed
- Unusable class was removed
