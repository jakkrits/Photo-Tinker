//
//  SPKCorePinView.h
//  Spark IOS
//
//  Copyright (c) 2013 Spark Devices. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DevicePin.h"

#define isiPhone5                   (([[UIScreen mainScreen] bounds].size.height == 568)?TRUE:FALSE)

/*
    A rather complicated class to programatically draw a pin. It
    takes into account tall and short iPhones. It is all based on
    layers with each layer displaying a different type of interaction.
 */
@class SPKCorePinView;

@protocol SPKCorePinViewDelegate <NSObject>

- (void)pinViewTapped:(SPKCorePinView *)pinView inPin:(BOOL)inPin;
- (void)pinViewAdjusted:(SPKCorePinView *)pinView newValue:(NSUInteger)newValue;
- (void)pinViewHeld:(SPKCorePinView *)pinView;

@end

@interface SPKCorePinView : UIView

@property (nonatomic, strong) DevicePin *pin;
@property (nonatomic, readonly) BOOL active;
@property (nonatomic, readonly) BOOL sliding;
@property (weak) NSObject<SPKCorePinViewDelegate> *delegate;

- (void)refresh;
- (void)deactivate;
- (void)activate;
- (void)hideDetails;
- (void)showDetails;
- (void)noslider;
- (void)slider;

@end
