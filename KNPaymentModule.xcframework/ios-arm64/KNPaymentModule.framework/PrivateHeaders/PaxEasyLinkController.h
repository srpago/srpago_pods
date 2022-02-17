//
//  PaxEasyLinkController.h
//  PaxEasyLinkController
//
//  Created by pax on 16/8/19.
//  Copyright © 2016年 jobten. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PaxEasyLinkConst.h"
#import "PaxEasyLinkProtocol.h"
#import "PaxReportResponse.h"

@protocol PaxEasyReportDelegate <NSObject>//app遵守的协议
@optional


/**
 onReportSearchModeWithPrompts
 @param prompts prompts  the prompts of current search card
 @param model  *       <p> {@link SearchMode#MSR_SWIPE} -  prompts:"Please Swipe Card"
 *       <p> {@link SearchMode#ICC_INSERT} - prompts:"Please Insert Card"
 *       <p> {@link SearchMode#MSR_SWIPE_AND_ICC_INSERT} - prompts:"Please Swipe/Insert Card"
 *       <p> {@link SearchMode#PICC_TAP} - prompts:"Please Tap Card"
 *       <p> {@link SearchMode#MSR_SWIPE_PICC_TAP} - prompts:"Please Swipe/Tap Card"
 *       <p> {@link SearchMode#ICC_INSERT_AND_PICC_TAP} - prompts:"Please Insert/Tap Card"
 *       <p> {@link SearchMode#MSR_SWIPE_AND_ICC_INSERT_AND_PICC_TAP} - prompts:"PLS Swipe/Insert/Tap Card"
 *       <p> {@link SearchMode#SWIPE_FALLBACK} - prompts:"Fallback, PLS swipe card"
 */
- (void)onReportSearchModeWithPrompts:(NSString *)prompts searchMode:(NSInteger)model;

/**
 * @param prompts the prompts of the processing read card<br>
 * @param type  current type of detected card, when the type is<br>
 *              <p> {@link DketectType#CONTACTLESS} -  contactless card client should flash the light and show prompts,
 *              <p> {@link DetectType#CONTACT}  - contact card, client may show the prompts
 *              <p> {@link DetectType#MAGNETIC}  - magnetic card, client may show the prompts<br>
 * @param readCardStatus  the status of reading card<br>
 *       <p> {@link ReadCardStatus#STATUS_NOT_READY}
 *       <p> {@link ReadCardStatus#STATUS_IDLE}
 *       <p> {@link ReadCardStatus#STATUS_READY_TO_READ}
 *       <p> {@link ReadCardStatus#STATUS_PROCESSING} - [detectType:CONTACTLESS,prompts:"EMV Contactless Processing"], [detectType:CONTACT,prompts:"Processing, Not Remove"],[detectType:MAGNETIC,prompts:"Processing, Not Remove"]
 *       <p> {@link ReadCardStatus#STATUS_READ_CARD_SUCCESSFULLY} - prompts:"Read Card SUCCESS"
 *       <p> {@link ReadCardStatus#STATUS_PROCESSING_ERROR_CONTACTLESS_ERROR}
 *       <p> {@link ReadCardStatus#STATUS_PROCESSING_ERROR_CONTACTLESS_CONDITIONS_NOT_SATISFIED}
 *       <p> {@link ReadCardStatus#STATUS_PROCESSING_ERROR_CONTACTLESS_COLLISION_DETECTED}
 *       <p> {@link ReadCardStatus#STATUS_CARD_NOT_REMOVED_FROM_READER} - prompts:"Please Remove Card"
 *       <p> {@link ReadCardStatus#DETECTED_CARD_SUCCESSFULLY} - prompts:"Detected Card"
 */
- (void)onReadCardWithPrompts:(NSString*)prompts detectType:(NSInteger)type readCardStatus:(NSInteger)readCardStatus;

/**
 * @param prompts       the processing prompts of enter pin<br>
 * @param pinLen        entered Pin Length<br>
 * @param enterPinEvent entered Pin Status<br>
 *                      <p> {@link EnterPinEvent#INIT}  - Start input pin
 *                      <p> {@link EnterPinEvent#INPUT} - PIN is being inputted
 *                      <p> {@link EnterPinEvent#CANCEL}- POS’s Cancel key was clicked
 *                      <p> {@link EnterPinEvent#CLEAR} - POS’s clear key was clicked
 *                      <p> {@link EnterPinEvent#ENTER} - POS’s enter key was clicked
 *                      <p> {@link EnterPinEvent#RETRY} - PIN Error, Retry
 *                      <p> {@link EnterPinEvent#LAST}  - Last Enter PIN
 */
- (void)onEnterPinWithPrompts:(NSString*)prompts pinLen:(NSInteger)pinLen enterPinEvent:(NSString *)enterPinEvent;


/**
 * @param prompts the prompts of Select APP.<br>
 *                <p> appList is empty-The operation of selecting app at POS terminal, client just need to display prompts, such as "Selecting APP"
 *                <p> appList not empty -The operation of selecting app on client side, so display the appList for user selection. and the title can be "Pls Select APP"<br>
 * @param timeout  The valid time of select app, in seconds(s)<br>
 * @param appList The “appList” is the candidate application list for EMV application select.<br>
 *               <p> If the POS terminal doesn’t have screen, the operation of selecting app will at client side, the reported appList shall be the EMV candidate application list
 *                <p> if the POS terminal has screen,the operation of selecting app will at POS terminal side, the reported appList shall be null;
 * @return The response of selected APP with status code, the selected appLabel and selected appIndex. see {@link com.paxsz.easylink.model.AppSelectResponse}
 *  <p> if user selection is normal and select app successfully, pack the AppSelectResponse with appSelectResponse.setStatus({@link com.paxsz.easylink.model.AppSelectResponse.SelAppStatus#SUCCESS}), appSelectResponse.setAppLabel("appLabel"), appSelectResponse.setAppIndex();<br>
 *  <p> if select app has timeout, pack the AppSelectResponse with appSelectResponse.setStatus({@link com.paxsz.easylink.model.AppSelectResponse.SelAppStatus#TIMEOUT});<br>
 *  <p> if select app was canceled by user, pack the AppSelectResponse with appSelectResponse.setStatus({@link com.paxsz.easylink.model.AppSelectResponse.SelAppStatus#CANCEL});<br>
 *  <p> if appList is empty, pack the AppSelectResponse with appSelectResponse.setStatus({@link com.paxsz.easylink.model.AppSelectResponse.SelAppStatus#NO_APP});<br>
 
 */
- (PaxReportResponse *)onSelectAppWithPrompts:(NSString *)prompts timeout:(int)timeout list:(NSArray *)appList;



/**
 * Set parameter from smart device while startTransaction<br>
 * For example, if the payment app in smart device need to support multi-acquirer, then the payment app in smart device need to set the TAG 0219, 021A first. The EasyLink app will invoke getData to get the values of TAGs as TAG 0219, 021A indicated. Then pack the TLVs data and report to the smart device. The smart device need to unpack the TLV data, and can get to know the corresponding KEY information (PIN key type, PIN key index, etc) according to the unpacked TLV data, then set the TAG 0202, 0203 to the PinPad (EasyLink App)<br>
 * NOTE:<p>
 * 1.Except the multi-acquirer scenario, the smart device can also set the parameters to support different usage scenario.<br>
 * 2.If TAG 0205 and TAG 0206 are set, then the value of the sensitive data shall be encrypted.<br>
 *
 * @param prompts    "Please Set Param"
 * @param configTLVs reported data of config tag(such as 0219) which were set before startTransaction<br>
 *                   <p>“configTlv” is the TLV String converted from TLV(bcd) that the EasyLink App get these TLVs (bcd) data according to the TAGs as TAG 0219 indicated;<br>
 * @param emvTLVs    reported data of emv tag(such as 021A) which were set before startTransaction
 *                   <p>“emvTlv” is the TLV String converted from TLV(bcd) that the EasyLink App get the these TLVs (bcd) data according to the TAGs as TAG 021A indicated;<br>
 * @param timeout    timeout(s)
 * @return set param such as pin key index and type
 */
- (NSArray<TlvItem *> *)onSetParamToPinPadWithPrompts:(NSString *)prompts configTLVs:(NSArray<TlvItem *> *)configTLVs emvTLVs:(NSArray<TlvItem *> *)emvTLVs timeout:(NSInteger)timeout;
@end

@interface PaxEasyLinkController : NSObject<PaxBluetoothDelegate, PaxTransDelegate>

@property(nonatomic,weak) id<PaxEasyReportDelegate>delegate;
#pragma mark 单例模式

/*!
 @abstract get PaxEasyLinkController instance
 @return    PaxEasyLinkController instance
 */
+ (PaxEasyLinkController *)getInstance;


@end

