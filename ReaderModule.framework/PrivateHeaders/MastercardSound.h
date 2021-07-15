//
//  MastercardSound.h
//  ReaderModule
//
//  Created by Fernando Bustos on 07/07/21.
//  Copyright © 2021 SrPago. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MastercardSound: NSObject
/// Method of indicating whether MasterCard's sound needs to be played
/// @param brand Brand Card Name
    - (void) makeSoundBy:(NSString *) brand;
@end

NS_ASSUME_NONNULL_END
