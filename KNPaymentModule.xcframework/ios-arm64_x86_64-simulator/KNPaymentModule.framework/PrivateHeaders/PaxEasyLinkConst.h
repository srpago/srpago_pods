//
//  PaxEasyLinkConst.h
//  PaxEasyLinkController
//
//  Created by pax on 16/8/19.
//  Copyright © 2016年 jobten. All rights reserved.
//

//
//
/*!
  @abstract BluetoothInfo
 */

@interface BluetoothInfo : NSObject

/*!
 @abstract identifier
 */
@property (nonatomic, copy) NSString *deviceId;
/*!
 @abstract bluetooth name
 */
@property (nonatomic, copy) NSString *deviceName;

@end

/*!
 @abstract PageContentInfo
 */
@interface PageContentInfo : NSObject
/*!
 @abstract widget name
 */
@property (nonatomic, copy) NSString *widgetName;
/*!
 @abstract text
 */
@property (nonatomic, copy) NSString *text;

@end

/*!
 @abstract ActionType
 @constant SIGNATURE_DATA the signature returned by the pos terminal which is signed by the customer.JBIG format
 @constant COMMENTSTAR_DATA the number of stars returned by the pos terminal which is commented or rated by customer.
 */
typedef enum
{
    SIGNATURE_DATA = 4,
    COMMENTSTAR_DATA,
    
}ActionType;



/*!
 @abstract PageMsgInfo
 */
@interface PageMsgInfo: NSObject

/*!
 @abstract actionType
 */
@property (nonatomic, assign) ActionType actionType;

/*!
 @abstract pageData
 */
@property (nonatomic, copy) NSData *pageData;
@end


/*!
 @abstract a BER-TLV item
 */
@interface TlvItem : NSObject

/*!
 @abstract tag
 */
@property NSData *tag;
/*!
 @abstract value
 */
@property NSData *value;

@end

 /*!
 @abstract DataType
 @constant TRANSACTION_DATA  standard emv tlv tag data
 @constant CONFIGURATION_DATA config data
 */
typedef enum
{
    TRANSACTION_DATA = 1,     //standard emv tlv tag data
    CONFIGURATION_DATA,       //config data
} DataType;

#pragma mark 回调函数========================================
/*!
 @abstract deviceInfo return block. see BluetoothInfo
 @param deviceInfo device Info. see @link BluetoothInfo @/link
 */
typedef void (^onSearchOneDeviceCB)(BluetoothInfo *deviceInfo);

/*!
 @abstract	processing block
 @param 	current current process value
 @param 	total total process value
 */
typedef void (^onProcessCB)(NSInteger current, NSInteger total);

/*!
 @abstract stop download block
 @return   YES:will stop downloading process NO:download
 */
typedef BOOL (^onStopCB)(void);
#pragma mark --设置日志等级========================================
/*!
 @abstract pax log level
 @constant PAX_LOG_LEVEL_NONE   no log
 @constant PAX_LOG_LEVEL_ERR    error log
 @constant PAX_LOG_LEVEL_WRN    warning log
 @constant PAX_LOG_LEVEL_DBG    debug log
 @constant PAX_LOG_LEVEL_INFO   all log
 */
typedef enum {
    
    PAX_LOG_LEVEL_NONE    = 0,
    PAX_LOG_LEVEL_ERR     = 1,
    PAX_LOG_LEVEL_WRN     = 2,
    PAX_LOG_LEVEL_DBG     = 3,
    PAX_LOG_LEVEL_INFO    = 4
    
} PaxLogLevel;
/*!
 @abstractset log level
 @param level log level
 */
void PaxSetLogLevel(PaxLogLevel level);

