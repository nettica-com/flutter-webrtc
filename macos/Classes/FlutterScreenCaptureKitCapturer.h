#import <Foundation/Foundation.h>
#import <WebRTC/WebRTC.h>

typedef void (^FlutterScreenCaptureKitStopHandler)(NSError * _Nullable error);

@interface FlutterScreenCaptureKitCapturer : NSObject

// Reports stops that originate outside stopCaptureWithCompletion:, such as
// the user ending screen sharing from macOS system UI.
@property(nonatomic, copy, nullable) FlutterScreenCaptureKitStopHandler onCaptureStopped;

- (instancetype)initWithDelegate:(id<RTCVideoCapturerDelegate>)delegate;

- (void)startCaptureWithFPS:(NSInteger)fps
                   sourceId:(NSString* _Nullable)sourceId
                  onStarted:(void (^)(NSError * _Nullable error))onStarted;

- (void)stopCaptureWithCompletion:(void (^)(void))completion;

@end
