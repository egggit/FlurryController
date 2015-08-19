//
//  FlurryController.m

#import "Flurry.h"
#import "FlurryController.h"

@implementation FlurryController

#if !TARGET_IPHONE_SIMULATOR
#define ActivateFlurry
#endif





////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma mark - Class Methods

+ (void)setAPIKey:(NSString *)apiKey
{
    
#ifdef ActivateFlurry
    [Flurry setCrashReportingEnabled:YES];
#ifdef DEBUG
    [Flurry setDebugLogEnabled:YES];
#endif
    [Flurry setSessionReportsOnPauseEnabled:YES];
    [Flurry setAppVersion:[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"]];
    [Flurry startSession:apiKey];
    
#endif
    
}


+ (void)startLogAllPageViewsForRootViewController:(UIViewController *)rootViewController
{
#ifdef ActivateFlurry
    [Flurry logAllPageViewsForTarget:rootViewController];
    [Flurry logPageView];
#endif
}


+ (void)stopLogAllPageViewsForRootViewController:(UIViewController *)rootViewController
{
#ifdef ActivateFlurry
    [Flurry stopLogPageViewsForTarget:rootViewController];
#endif
}


+ (void)logEvent:(NSString *)eventName
{
#ifdef ActivateFlurry
    [Flurry logEvent:eventName];
#endif
}


+ (void)logEvent:(NSString *)eventName withParameters:(NSDictionary *)parameters
{
#ifdef ActivateFlurry
    [Flurry logEvent:eventName withParameters:parameters];
#endif
}


+ (void)startTimedLogEventName:(NSString *)eventName withParameters:(NSDictionary *)parameters
{
#ifdef ActivateFlurry
    [Flurry logEvent:eventName withParameters:parameters timed:YES];
#endif
}


+ (void)stopTimedLogEventName:(NSString *)eventName withParameters:(NSDictionary *)parameters
{
#ifdef ActivateFlurry
    [Flurry endTimedEvent:eventName withParameters:parameters];
#endif
}


+ (void)logErrorWithEventName:(NSString *)eventName message:(NSString *)message error:(NSError *)error
{
#ifdef ActivateFlurry
    [Flurry logError:eventName message:message error:error];
#endif
}

@end
