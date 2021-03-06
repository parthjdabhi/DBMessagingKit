//
//  DBInteractiveKeyboardController.h
//
//
//  GitHub
//  https://github.com/DevonBoyer/DBMessagingKit
//
//
//  Created by Devon Boyer on 2014-10-05.
//  Copyright (c) 2014 Devon Boyer. All rights reserved.
//
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import <UIKit/UIKit.h>

@class DBInteractiveKeyboardController;

/**
 *  Posted when the system keyboard frame changes.
 */
extern NSString * const DBInteractiveKeyboardDidChangeFrameNotification;

/**
 *  Contains the new keyboard frame wrapped in an 'NSValue' object.
 */
extern NSString * const DBInteractiveKeyboardDidChangeFrameUserInfoKey;

/**
 *  The 'DBInteractiveKeyboardControllerDelegate' protocol defines methods that
 *  allow you to respond to the frame change events of the system keyboard.
 *
 *  A 'DBInteractiveKeyboardController' object also posts the 'DBInteractiveKeyboardControllerKeyboardDidChangeFrameNotification'
 *  in response to frame change events of the system keyboard.
 */
@protocol DBInteractiveKeyboardControllerDelegate <NSObject>

@required

/**
 *  Tells the delegate that the keyboard frame has changed.
 *
 *  @param keyboardController The keyboard controller that is notifying the delegate.
 *  @param keyboardFrame      The new frame of the keyboard in the coordinate system of the 'contextView'.
 */
- (void)keyboardController:(DBInteractiveKeyboardController *)keyboardController keyboardDidChangeFrame:(CGRect)keyboardFrame;

@optional

/**
 *  Tells the delegate that the keyboard will appear.
 */
- (void)keyboardControllerWillAppear:(DBInteractiveKeyboardController *)keyboardController;

/**
 *  Tells the delegate that the keyboard did appear.
 */
- (void)keyboardControllerDidAppear:(DBInteractiveKeyboardController *)keyboardController;

@end

/**
 *  An instance of 'DBInteractiveKeyboardController' manages responding to the hiding and showing
 *  of the system keyboard for editing its 'textView' within its specified 'contextView'.
 *  It also controls user interaction with the system keyboard via its 'panGestureRecognizer',
 *  allow the user to interactively pan the keyboard up and down in the 'contextView'.
 *
 *  When the system keyboard frame changes, it posts the 'DBInteractiveKeyboardControllerKeyboardDidChangeFrameNotification'.
 */
@interface DBInteractiveKeyboardController : NSObject

/**
 *  The object that acts as the delegate of the keyboard controller.
 */
@property (weak, nonatomic) id<DBInteractiveKeyboardControllerDelegate> delegate;

/**
 *  The text view in which the user is editing with the system keyboard.
 */
@property (weak, nonatomic) UITextView *textView;

/**
 *  The view in which the keyboard will be shown. This should be the parent or a sibling of `textView`.
 */
@property (weak, nonatomic) UIView *contextView;

/**
 *  The view in which the keyboard will be shown. This should be the parent or a sibling of `textView`.
 */
@property (weak, nonatomic) UIPanGestureRecognizer *panGestureRecognizer;

/**
 *  Returns 'YES' if the keyboard is currently visible, 'NO' otherwise.
 */
@property (assign, nonatomic) BOOL keyboardIsVisible;

/**
 *  Specifies the distance from the keyboard at which the 'panGestureRecognizer'
 *  should trigger user interaction with the keyboard by panning.
 *
 *  @discussion The x value of the point is not used.
 */
@property (assign, nonatomic) CGPoint keyboardTriggerPoint;

/**
 *  Returns the current frame of the keyboard if it is visible, otherwise `CGRectNull`.
 */
@property (assign, nonatomic) CGRect currentKeyboardFrame;

/**
 *  Creates a new keyboard controller object with the specified textView, contextView, panGestureRecognizer, and delegate.
 *
 *  @param textView The text view in which the user is editing with the system keyboard. This value must not be `nil`.
 *  @param contextView The view in which the keyboard will be shown. This should be the parent or a sibling of `textView`. This 
 *  value must not be 'nil'.
 *  @param panGestureRecognizer The pan gesture recognizer responsible for handling user interaction with the system keyboard. 
 *  This value must not be 'nil'.
 *  @param delegate The object that acts as the delegate of the keyboard controller.
 *
 *  @return An initialized 'DBInteractiveKeyboardController'
 */
- (instancetype)initWithTextView:(UITextView *)textView
                     contextView:(UIView *)contextView
            panGestureRecognizer:(UIPanGestureRecognizer *)panGestureRecognizer
                        delegate:(id<DBInteractiveKeyboardControllerDelegate>)delegate;

/**
 *  Tells the keyboard controller that it should begin listening for system keyboard notifications.
 */
- (void)beginListeningForKeyboard;

/**
 *  Tells the keyboard controller that it should end listening for system keyboard notifications.
 */
- (void)endListeningForKeyboard;

@end
