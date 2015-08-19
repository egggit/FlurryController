//
//  FlurryController.h

#import <Foundation/Foundation.h>


////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  Call this macro during viewWillAppear to start recording view controller uptime.
 */
#define FlurryTimedViewWillAppear() [FlurryController startTimedLogEventName:[NSString stringWithFormat:@"%@_UpTime", NSStringFromClass([self class])] withParameters:nil]

/**
 *  Call this macro during viewWillDisappear to stop recording view controller uptime.
 */
#define FlurryTimedViewWillDisappear() [FlurryController startTimedLogEventName:[NSString stringWithFormat:@"%@_UpTime", NSStringFromClass([self class])] withParameters:nil]


/**
 *  Handling Flurry related APIs, for readablility
 *
 *  @note: FlurryController will not work under simulator for obvious reason.
 */
@interface FlurryController : NSObject





////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark - Class Methods

/**
 *  Set API with Key.
 *
 *  @note: this has to execute first.
 *
 *  @param apiKey app key get from Flurry website.
 */
+ (void)setAPIKey:(NSString *)apiKey;

/**
 *  Call this method during application:didFinishLaunchingWithOptions:
 *
 *  @param rootViewController RootViewController of your window.
 */
+ (void)startLogAllPageViewsForRootViewController:(UIViewController *)rootViewController;

/**
 *  Call this method at applicationWillTerminate:
 *
 *  @param rootViewController RootViewController of your window.
 */
+ (void)stopLogAllPageViewsForRootViewController:(UIViewController *)rootViewController;

/**
 *  Log event with name, no other parameters.
 *
 *  @param eventName Event Name.
 */
+ (void)logEvent:(NSString *)eventName;

/**
 *  Log event with event name & parameters.
 *
 *  @param eventName  Name of the event.
 *  @param parameters Parameter in NSDictionary.
 */
+ (void)logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters;

/**
 *  Start Log with event name & parameter.
 *
 *  @note: call stopTimedLogEventName:withParameters: when finish.
 *
 *  @param eventName  Name of the event.
 *  @param parameters Parameter in NSDictionary.
 */
+ (void)startTimedLogEventName:(NSString *)eventName withParameters:(NSDictionary *)parameters;

/**
 *  Stop Log with event name & parameter.
 *
 *  @note: call startTimedLogEventName:withParameters: before using this method.
 *
 *  @param eventName  Name of the event.
 *  @param parameters Parameter in NSDictionary.
 */
+ (void)stopTimedLogEventName:(NSString *)eventName withParameters:(NSDictionary *)parameters;

@end
