//
// UIScrollView+SVInfiniteScrolling.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>

@class SVInfiniteScrollingView;

@interface UIScrollView (SVInfiniteScrolling)

typedef NS_ENUM(NSUInteger, SVInfiniteScrollingPosition) {
    SVInfiniteScrollingPositionTop = 0,
    SVInfiniteScrollingPositionBottom,
};

- (void)addInfiniteScrollingWithActionHandler:(void (^)(void))actionHandler;
- (void)addInfiniteScrollinhWithActionHandler:(void (^)(void))actionHandler position:(SVInfiniteScrollingPosition)position;
- (void)triggerInfiniteScrolling;

@property (nonatomic, strong, readonly) SVInfiniteScrollingView *infiniteScrollingView;
@property (nonatomic, assign) BOOL showsInfiniteScrolling;

@end

typedef NS_OPTIONS(NSUInteger, SVInfiniteScrollingState) {
    SVInfiniteScrollingStateStopped = 0,
    SVInfiniteScrollingStateTriggered = 1 << 0,
    SVInfiniteScrollingStateLoading = 1 << 1,
    SVInfiniteScrollingStateAll = 1 << 2
};

@interface SVInfiniteScrollingView : UIView

@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle;
@property (nonatomic, readonly) SVInfiniteScrollingState state;
@property (nonatomic, readwrite) BOOL enabled;

- (void)setCustomView:(UIView *)view forState:(SVInfiniteScrollingState)state;

- (void)startAnimating;
- (void)stopAnimating;

@end
