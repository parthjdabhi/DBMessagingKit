//
//  UIColor+Messaging.h
//
//
//  GitHub
//  https://github.com/DevonBoyer/DBMessagingKit
//
//
//  Created by Devon Boyer on 2014-09-18.
//  Copyright (c) 2014 Devon Boyer. All rights reserved.
//
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

@interface UIColor (Messaging)

/**
 *  @return A color object containing RBG values similar to the iOS 7 messages app gray bubble color.
 */
+ (UIColor *)iMessageGrayColor;

/**
 *  @return A color object containing RBG values similar to the iOS 7 messages app blue bubble color.
 */
+ (UIColor *)iMessageBlueColor;

/**
 *  @return A color object containing RBG values similar to the iOS 7 messages app green bubble color.
 */
+ (UIColor *)iMessageGreenColor;

/**
 *  @return A color object containing RBG values similar to the tint color of the iOS 7 messages app icons.
 */
+ (UIColor *)defaultToolbarTintColor;

/**
 *  Creates and returns a new color object whose brightness component is decreased by the given value, using the initial color 
 *  values of the receiver.
 *
 *  @param value A floating point value describing the amount by which to decrease the brightness of the receiver.
 *
 *  @return A new color object whose brightness is decreased by the given values. The other color values remain the same as the 
 *  receiver.
 */
- (UIColor *)colorByDarkeningColorWithValue:(CGFloat)value;

@end
