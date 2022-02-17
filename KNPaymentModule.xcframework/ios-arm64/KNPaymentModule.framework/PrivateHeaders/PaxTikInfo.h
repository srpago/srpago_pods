//
//  PaxTikInfo.h
//  PaxEasyLink
//
//  Created by jim.J on 2019/4/2.
//  Copyright © 2019 PAX. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface PaxTikInfo : NSObject

/**
 groupIndex
 */
@property (nonatomic,assign)Byte groupIndex;

/**
 Soure key index
 */
@property (nonatomic,assign)Byte srcKeyIndex;

/**
 Ipek len
 */
@property (nonatomic,assign)Byte keyLen;

/**
 ipek
 */
@property (nonatomic,copy)NSData *ipek;

/**
 KSN
 */
@property (nonatomic,copy)NSData *KSN;
@end

NS_ASSUME_NONNULL_END
