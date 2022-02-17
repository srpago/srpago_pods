//
//  PaxEasyLinkProtocol.h
//  PaxEasyLinkController
//
//  Created by pax on 16/8/19.
//  Copyright © 2016年 jobten. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "PaxEasyLinkConst.h"
#import "PaxEasyLinkStatusCode.h"
#import "PaxKeyInfo.h"
#import "PaxKcvInfo.h"
#import "PaxTikInfo.h"
#pragma mark ===========BlueTooth=======================================
/*!
  @protocol PaxBluetoothDelegate
 */

/*!
 @abstract disconnected callback prototype (currently used for Bluetooth)
 @param addr    address
 @param name    name
 */
typedef void (^didDisconnectedBlock)(NSString *addr, NSString *name);

@protocol PaxBluetoothDelegate <NSObject>

/*!
 @abstract  Search devices
 @param timeout timeout for searching devices (ms)
 @param searchOneDeviceCB Success Block. @link onSearchOneDeviceCB @/link 
 */


- (void)startSearchDev:(NSInteger)timeout
  searchOneDeviceBlock:(onSearchOneDeviceCB)searchOneDeviceCB;

/*!
 @abstract  Build connection with BT
 @param deviceId bluetooth identifier
 @return  PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode)connectDevice:(NSString *)deviceId;

/*!
 @abstract  Build connection with BT
 @param deviceId bluetooth identifier
 @param block  call back when bt disconnected
 @return  PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode)connectDevice:(NSString *)deviceId didDisconnectedBlock:(didDisconnectedBlock)block;


/*!
 @abstract  Build connection with TCP/IP
 @param host ip of the pos terminal
 @param port port of connection
 @return PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode)connectDevice:(NSString *)host port:(NSInteger)port;

/*!
 @abstract closeDevice
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode)closeDevice;

/*!
 @abstract  check if connected
 @return true:connected, false:no connected
 */
- (BOOL)isConnected;

@end

#pragma mark -- transcation========================================

/*!
 @protocol PaxTransDelegate
 */
@protocol PaxTransDelegate <NSObject>


/*!
 @abstract startTransaction
 @discussion
   Detect card(MSR, EMV CHIP, EMV Contactless), and do corresponding processing.
   Read track1, track2, track3 data, if MSR is swiped
   Application selection, initial processing, terminal risk management, ODA, CVM, 1st GAC, if EMV Chip card is inserted
   Application selection, get final selected application data, Paywave/Mastercard contactless/... processing, restriction processing, ODA, CVM, ..., if EMV contactless card is tapped
 @return  PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode) startTransaction;

/*!
 @abstract completeTransaction
 @discussion
   Issuer data verification, perform script for EMV, EMV contactless card
 @return PaxEasyLinkRetCode
 */
-(PaxEasyLinkRetCode) completeTransaction;
/*!
 @abstract Get PINBLOCK
 @param PAN - non-shifted PAN data,  or "", if "", then POS terminal will use the PAN data stored (which read in StartTransaction API) to calculate the PINBLOCK
 @param pinCB [output] Pin
 @param ksnCB [output] ksn
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) inputPin:(NSString *)PAN pinBlock:(NSData**)pinCB ksnBlock:(NSData**)ksnCB;
/*!
 @abstract Encrypt data
 @param data  data to be encrypted
 @param encrypyedData [output] encrypted Result
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) encryptData: (NSData *)data encrypyedData:(NSData**)encrypyedData;


/*!
 @abstract increase ksn
 @return  PaxEasyLinkRetCode @/link
*/
 
- (PaxEasyLinkRetCode)increaseKsn:(NSData *)data;



/**
 writekey

 @param keyInfo keyInfo
 @param kcvInfo kcvInfo
 @return PaxEasyLinkRetCode
 */
- (PaxEasyLinkRetCode)writeKeyInfo:(PaxKeyInfo *)keyInfo kcvInfo:(PaxKcvInfo *)kcvInfo;


/**
 writeTIK

 @param tilInfo tilInfo
 @param kcvInfo kcvInfo
 @return PaxEasyLinkRetCode
 */
- (PaxEasyLinkRetCode)writeTIK:(PaxTikInfo *)tilInfo kcvInfo:(PaxKcvInfo *)kcvInfo;
/**
 send cancel

 @return PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode)sendCancel;

- (PaxEasyLinkRetCode)CalcMAC:(NSData*)data MAC:(NSData**)mac;
 /*!@abstract SetData
   Set up the TAG data (Terminal application parameter, Transaction parameter, EMV, EMV contactless)
 @param dataType see @link DataType @/link  TRANSACTION_DATA:1 CONFIGURATION_DATA:2
 @param dataList  TLV data list
 @param tagList tagList return
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) setData:(NSInteger)dataType dataList:(NSData*)dataList tagList:(NSData**)tagList;
/*!
 @abstract GetData
  Get value the TAG list (Terminal application parameter, Transaction parameter, EMV, EMV contactless)
 @param dataType  see @link DataType @/link  TRANSACTION_DATA:1 CONFIGURATION_DATA:2
 @param tagList  TAG list
 @param dataList tagList return
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) getData:(NSInteger)dataType tagList:(NSData*)tagList dataList:(NSData **)dataList;

/*!
 @abstract GetData
 Get value the TAG list (Terminal application parameter, Transaction parameter, EMV, EMV contactless)
 @param dataType  see @link DataType @/link  TRANSACTION_DATA:1 CONFIGURATION_DATA:2
 @param tagList  TAG list
 @param tlvArray an array of MposTlvItem objects
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) getData:(NSUInteger)dataType tagList:(NSData*)tagList tlvArray:(NSArray**)tlvArray;
/*!
 @abstract showPage
  Show message which configured in UI XML file in POS terminal
 @param pageName - The name of page which configured in UI XML file. To show the page;
 @param timeOut - showPage timeOut(ms)
 @param pageContentInfo -
 @discussion
  Set PageContentInfo arrayList, if need to change the displaying text of widget configured in UI XML.
 						eg. below is the configuration of textbox in UI XML file:
  						  "<TextBox name="prompt1" x="0" y="0" value="PAX" fontSize="0" textAlign="1" mode="0" keyAccept="1"></TextBox>"
 						If need to change the displaying text, set the showMsgInfo.widgetName = "prompt1", showMsgInfo.text = "PLS REMOVE CARD";
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) showPage:(NSString *)pageName timeOut:(short)timeOut pageContentInfo:(NSArray *)pageContentInfo PageMagInfo:(PageMsgInfo**)pageMsgInfo;

/*!
 @abstract showPage
 Show message which configured in UI XML file in POS terminal
 @param pageName - The name of page which configured in UI XML file. To show the page;
 @param timeOut - showPage timeOut(ms)
 @param pageContentInfo -
 @discussion
 Set PageContentInfo arrayList, if need to change the displaying text of widget configured in UI XML.
 eg. below is the configuration of textbox in UI XML file:
 "<TextBox name="prompt1" x="0" y="0" value="PAX" fontSize="0" textAlign="1" mode="0" keyAccept="1"></TextBox>"
 If need to change the displaying text, set the showMsgInfo.widgetName = "prompt1", showMsgInfo.text = "PLS REMOVE CARD";
 @return  PaxEasyLinkRetCode @/link
 */
- (PaxEasyLinkRetCode) showPage:(NSString *)pageName timeOut:(short)timeOut pageContentInfo:(NSArray *)pageContentInfo;
/*!
 @abstract fileDownLoad
  Send file to POS terminal,if update the UI in downloadProcessCB,UI must be updated in the main thread
 @param fileName - Name of file to be sent
 @param filePath - Path of file
 @param downloadProcessCB downloadProcess Block.see @link onProcessCB @/link
 @return  PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode) fileDownLoad:(NSString *)fileName filePath:(NSString *)filePath processBlock:(onProcessCB)downloadProcessCB;

/*!
 @abstract fileDownLoad
   Send file to POS terminal,if update the UI in downloadProcessCB,UI must be updated in the main thread. can stop downLoad process by @link onStopCB @/link
 @param fileName - Name of file to be sent
 @param filePath - Path of file
 @param downloadProcessCB downloadProcess Block.see @link onProcessCB @/link
 @param stopDownLoadCB  stop download Block.see @link onStopCB @/link
 @return  PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode) fileDownLoad:(NSString *)fileName filePath:(NSString *)filePath processBlock:(onProcessCB)downloadProcessCB stopDownLoadBlock:(onStopCB)stopDownLoadCB;

/*!
 @abstract Switch communication mode
 @param protoclType send protocol type
 @return  PaxEasyLinkRetCode @/link
 */
-(PaxEasyLinkRetCode) switchCompatibleMode: (NSInteger)protoclType;

@end
