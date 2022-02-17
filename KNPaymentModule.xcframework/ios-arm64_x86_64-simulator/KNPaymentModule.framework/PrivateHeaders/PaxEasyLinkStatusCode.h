//
//  PaxEasyLinkStatusCode.h
//  PaxEasyLinkController
//
//  Created by pax on 16/8/22.
//  Copyright © 2016年 jobten. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @abstract Return codes of EasyLink
 @discussion Please use @link  statusCode2String:@/link to transfer the return code into human readable string
 @constant EL_RET_OK = 0                        success
 
 @constant EL_COMM_RET_BASE                     BASE COMM error start value
 @constant EL_COMM_RET_CONNECTED                COMM connected
 @constant EL_COMM_RET_DISCONNECT_FAIL          COMM disconnect failed
 @constant EL_COMM_RET_PARAM_FILE_NOT_EXIS      param file not exist
 @constant EL_COMM_RET_OPEN_COMPATIBLE_MODE_FAIL open compatible mode fail
 
 @constant EL_UI_RET_BASE                       BASE UI error start value
 @constant EL_UI_RET_INVALID_WIDGETNAME         invalid widget name
 @constant EL_UI_RET_TIME_OUT                   time out
 @constant EL_UI_RET_INVALID_PAGE               invalid page
 @constant EL_UI_RET_PARSE_UI_FAILED            parse ui failed
 @constant EL_UI_RET_VALUESIZEERROR             widget value size
 @constant EL_UI_RET_INPUT_TYPE_ERROR           input type not find
 @constant EL_UI_RET_INVALID_WIDGETVALUE        invalid widget value
 @constant EL_UI_RET_USER_CANCEL                cancel exit
 @constant EL_UI_RET_MENUITEMNUM_ERROR          menuitem number = 0
 @constant EL_UI_RET_UNKOWN_ERROR               unknown error
 @constant EL_UI_RET_GETSIGNDATA_FALI           get signature data failed
 

 @constant EL_SECURITY_RET_BASE                 BASE security error start value
 @constant EL_SECURITY_RET_NO_KEY               key doesnot
 @constant EL_SECURITY_RET_PARAM_INVALID        Parameter
 @constant EL_SECURITY_RET_ENCRYPT_DATA_ERR     Encrypt data error
 @constant EL_SECURITY_RET_GET_PIN_BLOCK_ERR    Get pin block error
 @constant EL_SECURITY_RET_NO_PIN_INPUT         Not input pin
 @constant EL_SECURITY_RET_INPUT_CANCEL         user cancel
 @constant EL_SECURITY_RET_INPUT_TIMEOUT        input timeout
 @constant EL_SECURITY_RET_KEY_TYPE_ERR         key type error
 
 *****************abandoned return code*************************
 @constant EL_TRANS_RET_BASE					BASE transcation error start value
 @constant EL_TRANS_RET_ICC_RESET_ERR			ICC data reset error
 @constant EL_TRANS_RET_ICC_CMD_ERR				ICC command error
 @constant EL_TRANS_RET_ICC_BLOCK				ICC block
 @constant EL_TRANS_RET_EMV_RSP_ERR				EMV respond error
 @constant EL_TRANS_RET_EMV_APP_BLOCK			EMV app block
 @constant EL_TRANS_RET_EMV_NO_APP				EMV no app
 @constant EL_TRANS_RET_EMV_USER_CANCEL			EMV user cancel
 @constant EL_TRANS_RET_EMV_TIME_OUT			EMV timeout
 @constant EL_TRANS_RET_EMV_DATA_ERR			EMV data error
 @constant EL_TRANS_RET_EMV_NOT_ACCEPT			EMV transcation not accept
 @constant EL_TRANS_RET_EMV_DENIAL				EMV transcation denial
 @constant EL_TRANS_RET_EMV_KEY_EXP				EMV key expired
 @constant EL_TRANS_RET_EMV_NO_PINPAD			EMV no pinpad or pinpad not work
 @constant EL_TRANS_RET_EMV_NO_PASSWORD			EMV no pin
 @constant EL_TRANS_RET_EMV_SUM_ERR				EMV checksum error
 @constant EL_TRANS_RET_EMV_NOT_FOUND			EMV data not found
 @constant EL_TRANS_RET_EMV_NO_DATA				EMV no specified data
 @constant EL_TRANS_RET_EMV_OVERFLOW			EMV data overflow
 @constant EL_TRANS_RET_NO_TRANS_LOG			EMV translog entry
 @constant EL_TRANS_RET_RECORD_NOTEXIST			EMV no record
 @constant EL_TRANS_RET_LOGITEM_NOTEXIST		EMV no log item
 @constant EL_TRANS_RET_ICC_RSP_6985			EMV icc responded code 6985
 @constant EL_TRANS_RET_CLSS_USE_CONTACT		EMV use contact interface
 @constant EL_TRANS_RET_EMV_FILE_ERR			EMV file error
 @constant EL_TRANS_RET_CLSS_TERMINATE			EMV clss transcation terminated
 @constant EL_TRANS_RET_CLSS_FAILED				EMV clss transcation failed
 @constant EL_TRANS_RET_CLSS_DECLINE			EMV clss transcation declined
 @constant EL_TRANS_RET_CLSS_TRY_ANOTHER_CARD	Try another card (DPAS Only)
 @constant EL_TRANS_RET_PARAM_ERR				EMV error param
 @constant EL_TRANS_RET_CLSS_WAVE2_OVERSEA		International transaction(for VISA AP PayWave Level2 IC card use)
 @constant EL_TRANS_RET_CLSS_WAVE2_TERMINATED	Wave2 DDA response TLV format error
 @constant EL_TRANS_RET_CLSS_WAVE2_US_CARD		US card(for VISA AP PayWave L2 IC card use)
 @constant EL_TRANS_RET_CLSS_WAVE3_INS_CARD		Need to use IC card for the transaction(for VISA PayWave IC card use)
 @constant EL_TRANS_RET_CLSS_RESELECT_APP		Select the next AID in candidate list
 @constant EL_TRANS_RET_CLSS_CARD_EXPIRED		IC card is expired
 @constant EL_TRANS_RET_EMV_NO_APP_PPSE_ERR		No application is supported(Select PPSE is error)
 @constant EL_TRANS_RET_CLSS_USE_VSDC			Switch to contactless PBOC
 @constant EL_TRANS_RET_CLSS_CVMDECLINE			CVM result in decline for AE
 @constant EL_TRANS_RET_CLSS_REFER_CONSUMER_DEVICE	  Status Code returned by IC card is 6986, please see phone
 @constant EL_TRANS_RET_CLSS_LAST_CMD_ERR		      The last read record command is error(qPBOC Only)
 @constant EL_TRANS_RET_CLSS_API_ORDER_ERR	          Try another card (DPAS Only)
 @constant EL_EMV_RET_TRANS_FAIL					  transcation failed
 @constant EL_EMV_RET_TRANS_DECLINED				  transcation declined
 *****************abandoned return code*************************
 
 @constant EL_TRANS_RET_BASE                      base transcation error start value
 @constant EL_TRANS_RET_READ_CARD_FAIL            read card data fail
 @constant EL_TRANS_RET_CARD_BLOCKED              card is blocked
 @constant EL_TRANS_RET_USER_CANCELED             user cancel transcation
 @constant EL_TRANS_RET_TIME_OUT                  timeout
 @constant EL_TRANS_RET_CARD_DATA_ERROR           card data error
 @constant EL_TRANS_RET_TRANS_NOT_ACCEPT          trancation isn't accepted
 @constant EL_TRANS_RET_TRANS_FAILED              trancation is failed
 @constant EL_TRANS_RET_TRASN_DECLINED            trancation is declined
 @constant EL_TRANS_RET_NOT_SUPPORT               trancation is not supported
 @constant EL_TRANS_RET_EXPIRED                   card is expired
 
 @constant EL_FILEDOWNLOAD_ERR_BASE					  BASE filedownload error start value
 @constant EL_FILEDOWNLOAD_ERR_INVALID_PARAM		      invalid parameter
 @constant EL_FILEDOWNLOAD_ERR_DOWNLOAD_FILE_FAIL	  firmware file save failed
 @consatnt EL_FILEDOWNLOAD_RET_FIRMWARE_FAIL           download firmware failed
 @constant EL_FILEDOWNLOAD_ERR_FILE_OVERSIZE			  file over size
 ***********abandoned return code***************
 @constant EL_FILEDOWNLOAD_ERR_NOT_ALLOWED				  file not allowed
 ***********abandoned return code***************
 @constant EL_FILEDOWNLOAD_ERR_PARSE_ERR				  parse file failed
 

 @constant EL_PARAM_RET_BASE                          Base return code for parameter management module
 @constant EL_PARAM_RET_ERR_DATA                      Input data error.
 @constant EL_PARAM_RET_INVALID_PARAM                 Invalid parameter.
 @constant EL_PARAM_RET_PARTIAL_FAILED                Partial operation failed.
 @constant EL_PARAM_RET_ALL_FAILED                    All operation failed.
 @constant EL_PARAM_RET_BUFFER_TOO_SMALL T            the output buffer size is not enough.
 @constant EL_PARAM_RET_API_ORDER_ERR                 APIs are invoked in wrong order
 @constant EL_PARAM_RET_ENCRYPT_SENSITIVE_DATA_FAILED encrypted sensitive data failed
 
 @constant EL_SDK_RET_BASE                            Base return code for SDK
 @constant EL_SDK_RET_PARAM_INVALID                   invalid param
 @constant EL_SDK_RET_COMM_CONNECT_ERR                comm connect err
 @constant EL_SDK_RET_COMM_DISCONNECT_ERR             comm disconnect err
 @constant EL_SDK_RET_COMM_DISCONNECTED               comm disconnected
 @constant EL_SDK_RET_COMM_SEND_ERR                   comm sent err
 @constant EL_SDK_RET_COMM_RECV_ERR                   comm recv err
 @constant EL_SDK_PROTO_RET_BASE                      Base return code for proto err
 @constant EL_SDK_RET_PROTO_GENERAL_ERR               general error
 @constant EL_SDK_RET_PROTO_ARG_ERR                   argument error
 @constant EL_SDK_RET_PROTO_PACKET_TOO_LONG           packet too long
 @constant EL_SDK_RET_PROTO_NO_ENOUGH_DATA            receive data not enough
 @constant EL_SDK_RET_PROTO_DATA_FORMAT               data format error
 @constant EL_SDK_RET_PROTO_TIMEOUT timeout           timeout
 */

typedef enum {

    EL_RET_OK = 0,
    
    EL_COMM_RET_BASE                       = 1000,
    EL_COMM_RET_CONNECTED                  = (EL_COMM_RET_BASE +1),
    EL_COMM_RET_DISCONNECT_FAIL            = (EL_COMM_RET_BASE +2),
    EL_COMM_RET_NOTCONNECTED               = (EL_COMM_RET_BASE +3),
    EL_COMM_RET_OPEN_COMPATIBLE_MODE_FAIL       = (EL_COMM_RET_BASE +4),
    
    EL_UI_RET_BASE						    =(2000),
    EL_UI_RET_INVALID_WIDGETNAME		    =(EL_UI_RET_BASE + 1),
    EL_UI_RET_TIME_OUT					    =(EL_UI_RET_BASE + 2),
    EL_UI_RET_INVALID_PAGE			        =(EL_UI_RET_BASE +3),
    EL_UI_RET_PARSE_UI_FAILED			    =(EL_UI_RET_BASE +4),
    EL_UI_RET_VALUESIZEERROR			    =(EL_UI_RET_BASE +5),
    EL_UI_RET_INPUT_TYPE_ERROR 		        =(EL_UI_RET_BASE + 6),
    EL_UI_RET_INVALID_WIDGETVALUE 	        =(EL_UI_RET_BASE + 7),
    EL_UI_RET_USER_CANCEL				    =(EL_UI_RET_BASE + 8),
    EL_UI_RET_MENUITEMNUM_ERROR		        =(EL_UI_RET_BASE + 9),
    EL_UI_RET_UNKOWN_ERROR                  =(EL_UI_RET_BASE + 10),
    EL_UI_RET_GETSIGNDATA_FALI              =(EL_UI_RET_BASE + 11),
    
    EL_SECURITY_RET_BASE					=3000,
    EL_SECURITY_RET_NO_KEY					=(EL_SECURITY_RET_BASE + 1),
    EL_SECURITY_RET_PARAM_INVALID			=(EL_SECURITY_RET_BASE + 2),
    EL_SECURITY_RET_ENCRYPT_DATA_ERR		=(EL_SECURITY_RET_BASE + 3),
    EL_SECURITY_RET_GET_PIN_BLOCK_ERR		=(EL_SECURITY_RET_BASE + 4),
    EL_SECURITY_RET_NO_PIN_INPUT			=(EL_SECURITY_RET_BASE + 5),
    EL_SECURITY_RET_INPUT_CANCEL			=(EL_SECURITY_RET_BASE + 6),
    EL_SECURITY_RET_INPUT_TIMEOUT			=(EL_SECURITY_RET_BASE + 7),
    EL_SECURITY_RET_KEY_TYPE_ERR            =(EL_SECURITY_RET_BASE + 8),

    
    EL_TRANS_RET_BASE						= 4000,
    EL_TRANS_RET_READ_CARD_FAIL             =(EL_TRANS_RET_BASE + 2),
    EL_TRANS_RET_CARD_BLOCKED               =(EL_TRANS_RET_BASE + 3),
    EL_TRANS_RET_USER_CANCELED              =(EL_TRANS_RET_BASE + 7),
    EL_TRANS_RET_TIME_OUT                   =(EL_TRANS_RET_BASE + 8),
    EL_TRANS_RET_CARD_DATA_ERROR            =(EL_TRANS_RET_BASE + 9),
    EL_TRANS_RET_TRANS_NOT_ACCEPT           =(EL_TRANS_RET_BASE + 10),
    EL_TRANS_RET_TRANS_FAILED               =(EL_TRANS_RET_BASE + 43),
    EL_TRANS_RET_TRASN_DECLINED             =(EL_TRANS_RET_BASE +44),
    EL_TRANS_RET_NOT_SUPPORT                =(EL_TRANS_RET_BASE +46),
    EL_TRANS_RET_EXPIRED                    =(EL_TRANS_RET_BASE +47),
    
    //abandoned return code
    /*EL_TRANS_RET_ICC_RESET_ERR				=(EL_TRANS_RET_BASE + 1),
    EL_TRANS_RET_ICC_CMD_ERR				=(EL_TRANS_RET_BASE + 2),
    EL_TRANS_RET_ICC_BLOCK					=(EL_TRANS_RET_BASE + 3),
    EL_TRANS_RET_EMV_RSP_ERR				=(EL_TRANS_RET_BASE + 4),
    EL_TRANS_RET_EMV_APP_BLOCK				=(EL_TRANS_RET_BASE + 5),
    EL_TRANS_RET_EMV_NO_APP					=(EL_TRANS_RET_BASE + 6),
    EL_TRANS_RET_EMV_USER_CANCEL			=(EL_TRANS_RET_BASE + 7),
    EL_TRANS_RET_EMV_TIME_OUT				=(EL_TRANS_RET_BASE + 8),
    EL_TRANS_RET_EMV_DATA_ERR				=(EL_TRANS_RET_BASE + 9),
    EL_TRANS_RET_EMV_NOT_ACCEPT				=(EL_TRANS_RET_BASE + 10),
    EL_TRANS_RET_EMV_DENIAL					=(EL_TRANS_RET_BASE + 11),
    EL_TRANS_RET_EMV_KEY_EXP				=(EL_TRANS_RET_BASE + 12),
    EL_TRANS_RET_EMV_NO_PINPAD				=(EL_TRANS_RET_BASE + 13),
    EL_TRANS_RET_EMV_NO_PASSWORD			=(EL_TRANS_RET_BASE + 14),
    EL_TRANS_RET_EMV_SUM_ERR				=(EL_TRANS_RET_BASE + 15),
    EL_TRANS_RET_EMV_NOT_FOUND				=(EL_TRANS_RET_BASE + 16),
    EL_TRANS_RET_EMV_NO_DATA				=(EL_TRANS_RET_BASE + 17),
    EL_TRANS_RET_EMV_OVERFLOW				=(EL_TRANS_RET_BASE + 18),
    EL_TRANS_RET_NO_TRANS_LOG				=(EL_TRANS_RET_BASE + 19),
    EL_TRANS_RET_RECORD_NOTEXIST			=(EL_TRANS_RET_BASE + 20),
    EL_TRANS_RET_LOGITEM_NOTEXIST			=(EL_TRANS_RET_BASE + 21),
    EL_TRANS_RET_ICC_RSP_6985				=(EL_TRANS_RET_BASE + 22),
    EL_TRANS_RET_CLSS_USE_CONTACT			=(EL_TRANS_RET_BASE + 23),
    EL_TRANS_RET_EMV_FILE_ERR				=(EL_TRANS_RET_BASE + 24),
    EL_TRANS_RET_CLSS_TERMINATE				=(EL_TRANS_RET_BASE + 25),
    EL_TRANS_RET_CLSS_FAILED				=(EL_TRANS_RET_BASE + 26),
    EL_TRANS_RET_CLSS_DECLINE				=(EL_TRANS_RET_BASE + 27),
    EL_TRANS_RET_CLSS_TRY_ANOTHER_CARD		=(EL_TRANS_RET_BASE + 28),
    
    EL_TRANS_RET_PARAM_ERR					=(EL_TRANS_RET_BASE + 30),
    EL_TRANS_RET_CLSS_WAVE2_OVERSEA			=(EL_TRANS_RET_BASE + 31),
    EL_TRANS_RET_CLSS_WAVE2_TERMINATED		=(EL_TRANS_RET_BASE + 32),
    EL_TRANS_RET_CLSS_WAVE2_US_CARD			=(EL_TRANS_RET_BASE + 33),
    EL_TRANS_RET_CLSS_WAVE3_INS_CARD		=(EL_TRANS_RET_BASE + 34),
    EL_TRANS_RET_CLSS_RESELECT_APP			=(EL_TRANS_RET_BASE + 35),
    EL_TRANS_RET_CLSS_CARD_EXPIRED			=(EL_TRANS_RET_BASE + 36),
    EL_TRANS_RET_EMV_NO_APP_PPSE_ERR		=(EL_TRANS_RET_BASE + 37),
    EL_TRANS_RET_CLSS_USE_VSDC				=(EL_TRANS_RET_BASE + 38),
    EL_TRANS_RET_CLSS_CVMDECLINE			=(EL_TRANS_RET_BASE + 39),
    EL_TRANS_RET_CLSS_REFER_CONSUMER_DEVICE	=(EL_TRANS_RET_BASE + 40),
    EL_TRANS_RET_CLSS_LAST_CMD_ERR			=(EL_TRANS_RET_BASE + 41),
    EL_TRANS_RET_CLSS_API_ORDER_ERR			=(EL_TRANS_RET_BASE + 42),
    EL_TRANS_RET_EMV_FAIL					=(EL_TRANS_RET_BASE + 43),
    EL_TRANS_RET_EMV_DECLINED				=(EL_TRANS_RET_BASE + 44),*/
    
   
   
    EL_FILEDOWNLOAD_RET_BASE						=(7000),
    EL_FILEDOWNLOAD_ERR_INVALID_PARAM				=(EL_FILEDOWNLOAD_RET_BASE+1),
    EL_FILEDOWNLOAD_ERR_DOWNLOAD_FILE_FAIL			=(EL_FILEDOWNLOAD_RET_BASE+2),
    EL_FILEDOWNLOAD_RET_FIRMWARE_FAIL               =(EL_FILEDOWNLOAD_RET_BASE+3),
    EL_FILEDOWNLOAD_RET_FILE_OVERSIZE               =(EL_FILEDOWNLOAD_RET_BASE+4),
    EL_FILEDOWNLOAD_RET_PARSE_ERR                   =(EL_FILEDOWNLOAD_RET_BASE + 5),
    
    EL_PARAM_RET_BASE                            = 5000,
    EL_PARAM_RET_ERR_DATA                        = (EL_PARAM_RET_BASE + 1),
    EL_PARAM_RET_INVALID_PARAM                   = (EL_PARAM_RET_BASE + 2),
    EL_PARAM_RET_PARTIAL_FAILED                  = (EL_PARAM_RET_BASE + 3),
    EL_PARAM_RET_ALL_FAILED                      = (EL_PARAM_RET_BASE + 4),
    EL_PARAM_RET_BUFFER_TOO_SMALL                = (EL_PARAM_RET_BASE + 5),
    EL_PARAM_RET_API_ORDER_ERR	                 = (EL_PARAM_RET_BASE + 6),
    EL_PARAM_RET_ENCRYPT_SENSITIVE_DATA_FAILED	 =(EL_PARAM_RET_BASE + 7),
    
    EL_COMMON_RET_BASE                           = 6000,
    EL_COMMON_RET_INVALID_PARAM	                 =(EL_COMMON_RET_BASE + 1),	//Invalid parameter
    EL_COMMON_RET_FILE_SIZE_OVER_LIMIT	         =(EL_COMMON_RET_BASE + 2),	//File size over limit
    EL_COMMON_RET_FILE_TYPE_NOT_SPT	             =(EL_COMMON_RET_BASE + 3),	//File type not supported
    EL_COMMON_RET_FILE_SAVE_ERROR	             =(EL_COMMON_RET_BASE + 4),	//Save file data error
   
    
    EL_SDK_RET_BASE                              = 9000,
    EL_SDK_RET_PARAM_INVALID                     = (EL_SDK_RET_BASE + 1),
    EL_SDK_RET_COMM_CONNECT_ERR                  = (EL_SDK_RET_BASE + 2),
    EL_SDK_RET_COMM_DISCONNECT_ERR               = (EL_SDK_RET_BASE + 3),
    EL_SDK_RET_COMM_DISCONNECTED                 = (EL_SDK_RET_BASE + 4),
    EL_SDK_RET_COMM_SEND_ERR                     = (EL_SDK_RET_BASE + 5),
    EL_SDK_RET_COMM_RECV_ERR                 = (EL_SDK_RET_BASE + 6),
    
    
    EL_SDK_PROTO_RET_BASE = 9500,
    EL_SDK_RET_PROTO_GENERAL_ERR = (EL_SDK_PROTO_RET_BASE + 1),
    EL_SDK_RET_PROTO_ARG_ERR = (EL_SDK_PROTO_RET_BASE + 2),
    EL_SDK_RET_PROTO_PACKET_TOO_LONG = (EL_SDK_PROTO_RET_BASE + 3),
    EL_SDK_RET_PROTO_NO_ENOUGH_DATA = (EL_SDK_PROTO_RET_BASE + 4),
    EL_SDK_RET_PROTO_DATA_FORMAT = (EL_SDK_PROTO_RET_BASE + 5),
    EL_SDK_RET_PROTO_TIMEOUT = (EL_SDK_PROTO_RET_BASE + 6),
    EL_SDK_RET_USER_CANCEL   = (EL_SDK_PROTO_RET_BASE + 7),

    
  
    
} PaxEasyLinkRetCode;
/*!
 @abstract PaxEasyLinkStatusCode managers the return code
 */
 
@interface PaxEasyLinkStatusCode : NSObject
/*!
 @abstract get PaxEasyLinkStatusCode instance
 */

+ (id)sharedInstance;

/*!
 @abstract convert the return code to the human readable string
 @param code return code
 @return the converted string
 */
- (NSString *)statusCode2String:(PaxEasyLinkRetCode)code;

@end
