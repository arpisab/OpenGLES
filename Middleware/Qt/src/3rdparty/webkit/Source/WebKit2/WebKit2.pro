# WebKit2 - Qt4 build info

CONFIG += building-libs
CONFIG += depend_includepath

isEmpty(OUTPUT_DIR): OUTPUT_DIR = ../..

include($$PWD/../WebKit.pri)
include($$PWD/../JavaScriptCore/JavaScriptCore.pri)
include($$PWD/../WebCore/WebCore.pri)
include(WebKit2.pri)

TEMPLATE = lib
CONFIG += staticlib
TARGET = $$WEBKIT2_TARGET
DESTDIR = $$WEBKIT2_DESTDIR

# Build both debug and release configurations
mac: CONFIG += build_all

WEBKIT2_GENERATED_HEADERS = \
    $$WEBKIT2_GENERATED_SOURCES_DIR/AuthenticationManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/DownloadProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/NPObjectMessageReceiverMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginControllerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginProcessMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginProcessProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebApplicationCacheManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebApplicationCacheManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebContextMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebCookieManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebCookieManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebDatabaseManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebDatabaseManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebFullScreenManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebFullScreenManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebGeolocationManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebGeolocationManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebIconDatabaseMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebIconDatabaseProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebInspectorMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebInspectorProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebKeyValueStorageManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebKeyValueStorageManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebMediaCacheManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebMediaCacheManagerProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebPageMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebPageProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebProcessConnectionMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebProcessMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebProcessProxyMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebResourceCacheManagerMessages.h \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebResourceCacheManagerProxyMessages.h

WEBKIT2_GENERATED_SOURCES = \
    $$WEBKIT2_GENERATED_SOURCES_DIR/AuthenticationManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/DownloadProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/DrawingAreaMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/DrawingAreaProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/NPObjectMessageReceiverMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginControllerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginProcessMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginProcessProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/PluginProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebApplicationCacheManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebApplicationCacheManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebContextMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebCookieManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebCookieManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebDatabaseManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebDatabaseManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebFullScreenManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebFullScreenManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebGeolocationManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebGeolocationManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebIconDatabaseMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebIconDatabaseProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebInspectorMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebInspectorProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebKeyValueStorageManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebKeyValueStorageManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebMediaCacheManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebMediaCacheManagerProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebPageMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebPageProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebProcessConnectionMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebProcessMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebProcessProxyMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebResourceCacheManagerMessageReceiver.cpp \
    $$WEBKIT2_GENERATED_SOURCES_DIR/WebResourceCacheManagerProxyMessageReceiver.cpp

HEADERS += \
    Platform/CoreIPC/ArgumentDecoder.h \
    Platform/CoreIPC/ArgumentEncoder.h \
    Platform/CoreIPC/Arguments.h \
    Platform/CoreIPC/Attachment.h \
    Platform/CoreIPC/BinarySemaphore.h \
    Platform/CoreIPC/Connection.h \
    Platform/CoreIPC/CoreIPCMessageKinds.h \
    Platform/CoreIPC/DataReference.h \
    Platform/CoreIPC/HandleMessage.h \
    Platform/CoreIPC/MessageID.h \
    Platform/CoreIPC/MessageSender.h \
    Platform/Logging.h \
    Platform/Module.h \
    Platform/PlatformProcessIdentifier.h \
    Platform/Region.h \
    Platform/RunLoop.h \
    Platform/SharedMemory.h \
    Platform/WorkItem.h \
    Platform/WorkQueue.h \
    PluginProcess/PluginControllerProxy.h \
    PluginProcess/PluginProcess.h \
    PluginProcess/WebProcessConnection.h \
    Shared/ShareableBitmap.h \
    Shared/CacheModel.h \
    Shared/ChildProcess.h \
    Shared/CoreIPCSupport/DrawingAreaMessageKinds.h \
    Shared/CoreIPCSupport/DrawingAreaProxyMessageKinds.h \
    Shared/DictionaryPopupInfo.h \
    Shared/FontInfo.h \
    Shared/ImageOptions.h \
    Shared/ImmutableArray.h \
    Shared/ImmutableDictionary.h \
    Shared/LayerTreeContext.h \
    Shared/MutableArray.h \
    Shared/MutableDictionary.h \
    Shared/NativeWebKeyboardEvent.h \
    Shared/NativeWebMouseEvent.h \
    Shared/NativeWebWheelEvent.h \
    Shared/OriginAndDatabases.h \
    Shared/PlatformPopupMenuData.h \
    Shared/PrintInfo.h \
    Shared/SameDocumentNavigationType.h \
    Shared/SecurityOriginData.h \
    Shared/SessionState.h \
    Shared/StringPairVector.h \
    Shared/UpdateInfo.h \
    Shared/UserMessageCoders.h \
    Shared/VisitedLinkTable.h \
    Shared/WebCoreArgumentCoders.h \
    Shared/WebBackForwardListItem.h \
    Shared/WebCertificateInfo.h \
    Shared/WebContextMenuItem.h \
    Shared/WebContextMenuItemData.h \
    Shared/WebError.h \
    Shared/WebEvent.h \
    Shared/WebEventConversion.h \
    Shared/WebFindOptions.h \
    Shared/WebGeolocationPosition.h \
    Shared/WebGraphicsContext.h \
    Shared/WebImage.h \
    Shared/WebNavigationDataStore.h \
    Shared/WebNumber.h \
    Shared/WebOpenPanelParameters.h \
    Shared/WebPageCreationParameters.h \
    Shared/WebPageGroupData.h \
    Shared/WebPopupItem.h \
    Shared/WebPreferencesStore.h \
    Shared/WebProcessCreationParameters.h \
    Shared/WebURLRequest.h \
    Shared/WebURLResponse.h \
    Shared/WebUserContentURLPattern.h \
    Shared/Plugins/Netscape/NetscapePluginModule.h \
    Shared/Plugins/NPRemoteObjectMap.h \
    Shared/Plugins/NPIdentifierData.h \
    Shared/Plugins/NPObjectMessageReceiver.h \
    Shared/Plugins/NPObjectProxy.h \
    Shared/Plugins/NPVariantData.h \
    Shared/Plugins/PluginProcessCreationParameters.h \
    Shared/Plugins/PluginQuirks.h \
    Shared/qt/PlatformCertificateInfo.h \
    Shared/qt/UpdateChunk.h \
    Shared/qt/WebEventFactoryQt.h \
    UIProcess/Authentication/AuthenticationChallengeProxy.h \
    UIProcess/Authentication/AuthenticationDecisionListener.h \
    UIProcess/Authentication/WebCredential.h \
    UIProcess/Authentication/WebProtectionSpace.h \
    UIProcess/BackingStore.h \
    UIProcess/ChunkedUpdateDrawingAreaProxy.h \
    UIProcess/Downloads/DownloadProxy.h \
    UIProcess/DrawingAreaProxy.h \
    UIProcess/DrawingAreaProxyImpl.h \
    UIProcess/FindIndicator.h \
    UIProcess/GenericCallback.h \
    UIProcess/GeolocationPermissionRequestManagerProxy.h \
    UIProcess/GeolocationPermissionRequestProxy.h \
    UIProcess/Launcher/ProcessLauncher.h \
    UIProcess/Launcher/ThreadLauncher.h \
    UIProcess/PageClient.h \
    UIProcess/Plugins/PluginInfoStore.h \
    UIProcess/Plugins/PluginProcessProxy.h \
    UIProcess/Plugins/PluginProcessManager.h \
    UIProcess/ProcessModel.h \
    UIProcess/ResponsivenessTimer.h \
    UIProcess/TextChecker.h \
    UIProcess/TiledDrawingAreaProxy.h \
    UIProcess/VisitedLinkProvider.h \
    UIProcess/WebApplicationCacheManagerProxy.h \
    UIProcess/WebContext.h \
    UIProcess/WebContextInjectedBundleClient.h \
    UIProcess/WebContextMenuProxy.h \
    UIProcess/WebContextUserMessageCoders.h \
    UIProcess/WebCookieManagerProxy.h \
    UIProcess/WebCookieManagerProxyClient.h \
    UIProcess/WebDatabaseManagerProxy.h \
    UIProcess/WebDatabaseManagerProxyClient.h \
    UIProcess/WebDownloadClient.h \
    UIProcess/WebEditCommandProxy.h \
    UIProcess/WebFindClient.h \
    UIProcess/WebFormClient.h \
    UIProcess/WebFormSubmissionListenerProxy.h \
    UIProcess/WebFrameListenerProxy.h \
    UIProcess/WebFramePolicyListenerProxy.h \
    UIProcess/WebFrameProxy.h \
    UIProcess/WebFullScreenManagerProxy.h \
    UIProcess/WebGeolocationManagerProxy.h \
    UIProcess/WebGeolocationProvider.h \
    UIProcess/WebHistoryClient.h \
    UIProcess/WebIconDatabase.h \
    UIProcess/WebIconDatabaseClient.h \
    UIProcess/WebInspectorProxy.h \
    UIProcess/WebKeyValueStorageManagerProxy.h \
    UIProcess/WebLoaderClient.h \
    UIProcess/WebMediaCacheManagerProxy.h \
    UIProcess/WebNavigationData.h \
    UIProcess/WebOpenPanelResultListenerProxy.h \
    UIProcess/WebPageContextMenuClient.h \
    UIProcess/WebPageGroup.h \
    UIProcess/WebPageProxy.h \
    UIProcess/WebPolicyClient.h \
    UIProcess/WebPreferences.h \
    UIProcess/WebProcessProxy.h \
    UIProcess/WebResourceCacheManagerProxy.h \
    UIProcess/WebResourceLoadClient.h \
    UIProcess/WebUIClient.h \
    UIProcess/qt/WebContextMenuProxyQt.h \
    UIProcess/qt/WebPopupMenuProxyQt.h \
    WebProcess/ApplicationCache/WebApplicationCacheManager.h \
    WebProcess/Authentication/AuthenticationManager.h \
    WebProcess/Cookies/WebCookieManager.h \
    WebProcess/Downloads/Download.h \
    WebProcess/Downloads/DownloadManager.h \
    WebProcess/FullScreen/WebFullScreenManager.h \
    WebProcess/Geolocation/GeolocationPermissionRequestManager.h \
    WebProcess/Geolocation/WebGeolocationManager.h \
    WebProcess/IconDatabase/WebIconDatabaseProxy.h \
    WebProcess/InjectedBundle/DOM/InjectedBundleNodeHandle.h \
    WebProcess/InjectedBundle/DOM/InjectedBundleRangeHandle.h \
    WebProcess/InjectedBundle/InjectedBundle.h \
    WebProcess/InjectedBundle/InjectedBundleClient.h \
    WebProcess/InjectedBundle/InjectedBundleHitTestResult.h \
    WebProcess/InjectedBundle/InjectedBundleNavigationAction.h \
    WebProcess/InjectedBundle/InjectedBundlePageContextMenuClient.h \
    WebProcess/InjectedBundle/InjectedBundlePageFormClient.h \
    WebProcess/InjectedBundle/InjectedBundlePagePolicyClient.h \
    WebProcess/InjectedBundle/InjectedBundlePageUIClient.h \
    WebProcess/InjectedBundle/InjectedBundleScriptWorld.h \
    WebProcess/InjectedBundle/InjectedBundleUserMessageCoders.h \
    WebProcess/KeyValueStorage/WebKeyValueStorageManager.h \
    WebProcess/MediaCache/WebMediaCacheManager.h \
    WebProcess/ResourceCache/WebResourceCacheManager.h \
    WebProcess/Plugins/Netscape/JSNPMethod.h \
    WebProcess/Plugins/Netscape/JSNPObject.h \
    WebProcess/Plugins/Netscape/NPJSObject.h \
    WebProcess/Plugins/Netscape/NPRuntimeObjectMap.h \
    WebProcess/Plugins/Netscape/NPRuntimeUtilities.h \
    WebProcess/Plugins/Netscape/NetscapeBrowserFuncs.cpp \
    WebProcess/Plugins/Netscape/NetscapePlugin.h \
    WebProcess/Plugins/Netscape/NetscapePluginStream.h \
    WebProcess/Plugins/Plugin.h \
    WebProcess/Plugins/PluginController.h \
    WebProcess/Plugins/PluginView.h \
    WebProcess/Plugins/PluginProxy.h \
    WebProcess/Plugins/PluginProcessConnection.h \
    WebProcess/Plugins/PluginProcessConnectionManager.h \
    WebProcess/WebCoreSupport/WebChromeClient.h \
    WebProcess/WebCoreSupport/WebContextMenuClient.h \
    WebProcess/WebCoreSupport/WebDatabaseManager.h \
    WebProcess/WebCoreSupport/WebDragClient.h \
    WebProcess/WebCoreSupport/WebEditorClient.h \
    WebProcess/WebCoreSupport/WebErrors.h \
    WebProcess/WebCoreSupport/WebFrameLoaderClient.h \
    WebProcess/WebCoreSupport/WebGeolocationClient.h \
    WebProcess/WebCoreSupport/WebInspectorClient.h \
    WebProcess/WebCoreSupport/WebInspectorFrontendClient.h \
    WebProcess/WebCoreSupport/WebPlatformStrategies.h \
    WebProcess/WebCoreSupport/WebPopupMenu.h \
    WebProcess/WebCoreSupport/WebSearchPopupMenu.h \
    WebProcess/WebCoreSupport/qt/WebFrameNetworkingContext.h \
    WebProcess/WebPage/ChunkedUpdateDrawingArea.h \
    WebProcess/WebPage/DrawingArea.h \
    WebProcess/WebPage/DrawingAreaImpl.h \
    WebProcess/WebPage/FindController.h \
    WebProcess/WebPage/PageOverlay.h \
    WebProcess/WebPage/WebContextMenu.h \
    WebProcess/WebPage/WebEditCommand.h \
    WebProcess/WebPage/WebFrame.h \
    WebProcess/WebPage/WebInspector.h \
    WebProcess/WebPage/WebOpenPanelResultListener.h \
    WebProcess/WebPage/WebPage.h \
    WebProcess/WebPage/WebPageGroupProxy.h \
    WebProcess/WebProcess.h \
    $$WEBKIT2_GENERATED_HEADERS

SOURCES += \
    Platform/CoreIPC/ArgumentDecoder.cpp \
    Platform/CoreIPC/ArgumentEncoder.cpp \
    Platform/CoreIPC/Attachment.cpp \
    Platform/CoreIPC/BinarySemaphore.cpp \
    Platform/CoreIPC/Connection.cpp \
    Platform/CoreIPC/DataReference.cpp \
    Platform/CoreIPC/unix/AttachmentUnix.cpp \
    Platform/CoreIPC/unix/ConnectionUnix.cpp \
    Platform/Logging.cpp \
    Platform/Module.cpp \
    Platform/Region.cpp \
    Platform/RunLoop.cpp \
    Platform/WorkQueue.cpp \
    Platform/qt/ModuleQt.cpp \
    Platform/qt/RunLoopQt.cpp \
    Platform/qt/WorkQueueQt.cpp \
    Platform/unix/SharedMemoryUnix.cpp \
    PluginProcess/PluginControllerProxy.cpp \
    PluginProcess/PluginProcess.cpp \
    PluginProcess/WebProcessConnection.cpp \
    PluginProcess/qt/PluginControllerProxyQt.cpp \
    PluginProcess/qt/PluginProcessQt.cpp \
    Shared/Plugins/Netscape/NetscapePluginModule.cpp \
    Shared/Plugins/Netscape/NetscapePluginModuleNone.cpp \
    Shared/Plugins/Netscape/x11/NetscapePluginModuleX11.cpp \
    Shared/ShareableBitmap.cpp \
    Shared/Plugins/NPRemoteObjectMap.cpp \
    Shared/Plugins/NPIdentifierData.cpp \
    Shared/Plugins/NPObjectMessageReceiver.cpp \
    Shared/Plugins/NPObjectProxy.cpp \
    Shared/Plugins/NPVariantData.cpp \
    Shared/Plugins/PluginProcessCreationParameters.cpp \
    Shared/ChildProcess.cpp \
    Shared/DictionaryPopupInfo.cpp \
    Shared/FontInfo.cpp \
    Shared/ImmutableArray.cpp \
    Shared/ImmutableDictionary.cpp \
    Shared/MutableArray.cpp \
    Shared/MutableDictionary.cpp \
    Shared/OriginAndDatabases.cpp \
    Shared/PlatformPopupMenuData.cpp \
    Shared/PrintInfo.cpp \
    Shared/SecurityOriginData.cpp \
    Shared/SessionState.cpp \
    Shared/UpdateInfo.cpp \
    Shared/VisitedLinkTable.cpp \
    Shared/WebBackForwardListItem.cpp \
    Shared/WebContextMenuItem.cpp \
    Shared/WebContextMenuItemData.cpp \
    Shared/WebError.cpp \
    Shared/WebEvent.cpp \
    Shared/WebEventConversion.cpp \
    Shared/WebGeolocationPosition.cpp \
    Shared/WebGraphicsContext.cpp \
    Shared/WebKeyboardEvent.cpp \
    Shared/WebImage.cpp \
    Shared/WebMouseEvent.cpp \
    Shared/WebOpenPanelParameters.cpp \
    Shared/WebPageCreationParameters.cpp \
    Shared/WebPageGroupData.cpp \
    Shared/WebPlatformTouchPoint.cpp \
    Shared/WebPopupItem.cpp \
    Shared/WebPreferencesStore.cpp \
    Shared/WebProcessCreationParameters.cpp \
    Shared/WebTouchEvent.cpp \
    Shared/WebURLRequest.cpp \
    Shared/WebURLResponse.cpp \
    Shared/WebWheelEvent.cpp \
    Shared/qt/LayerTreeContextQt.cpp \
    Shared/qt/ShareableBitmapQt.cpp \
    Shared/qt/NativeWebKeyboardEventQt.cpp \
    Shared/qt/NativeWebMouseEventQt.cpp \
    Shared/qt/NativeWebWheelEventQt.cpp \
    Shared/qt/UpdateChunk.cpp \
    Shared/qt/WebCoreArgumentCodersQt.cpp \
    Shared/qt/WebEventFactoryQt.cpp \
    Shared/qt/WebURLRequestQt.cpp \
    Shared/qt/WebURLResponseQt.cpp \
    UIProcess/Authentication/AuthenticationChallengeProxy.cpp \
    UIProcess/Authentication/AuthenticationDecisionListener.cpp \
    UIProcess/Authentication/WebCredential.cpp \
    UIProcess/Authentication/WebProtectionSpace.cpp \
    UIProcess/BackingStore.cpp \
    UIProcess/qt/BackingStoreQt.cpp \
    UIProcess/ChunkedUpdateDrawingAreaProxy.cpp \
    UIProcess/Downloads/DownloadProxy.cpp \
    UIProcess/DrawingAreaProxy.cpp \
    UIProcess/DrawingAreaProxyImpl.cpp \
    UIProcess/FindIndicator.cpp \
    UIProcess/GeolocationPermissionRequestManagerProxy.cpp \
    UIProcess/GeolocationPermissionRequestProxy.cpp \
    UIProcess/Launcher/ProcessLauncher.cpp \
    UIProcess/Launcher/ThreadLauncher.cpp \
    UIProcess/Launcher/qt/ProcessLauncherQt.cpp \
    UIProcess/Launcher/qt/ThreadLauncherQt.cpp \
    UIProcess/Plugins/PluginInfoStore.cpp \
    UIProcess/Plugins/PluginProcessProxy.cpp \
    UIProcess/Plugins/PluginProcessManager.cpp \
    UIProcess/Plugins/WebPluginSiteDataManager.cpp \
    UIProcess/Plugins/qt/PluginInfoStoreQt.cpp \
    UIProcess/Plugins/qt/PluginProcessProxyQt.cpp \
    UIProcess/ResponsivenessTimer.cpp \
    UIProcess/TiledDrawingAreaProxy.cpp \
    UIProcess/VisitedLinkProvider.cpp \
    UIProcess/WebApplicationCacheManagerProxy.cpp \
    UIProcess/WebBackForwardList.cpp \
    UIProcess/WebContext.cpp \
    UIProcess/WebContextInjectedBundleClient.cpp \
    UIProcess/WebContextMenuProxy.cpp \
    UIProcess/WebCookieManagerProxy.cpp \
    UIProcess/WebCookieManagerProxyClient.cpp \
    UIProcess/WebDatabaseManagerProxy.cpp \
    UIProcess/WebDatabaseManagerProxyClient.cpp \
    UIProcess/WebDownloadClient.cpp \
    UIProcess/WebEditCommandProxy.cpp \
    UIProcess/WebFindClient.cpp \
    UIProcess/WebFormClient.cpp \
    UIProcess/WebFormSubmissionListenerProxy.cpp \
    UIProcess/WebFrameListenerProxy.cpp \
    UIProcess/WebFramePolicyListenerProxy.cpp \
    UIProcess/WebFrameProxy.cpp \
    UIProcess/WebFullScreenManagerProxy.cpp \
    UIProcess/WebGeolocationManagerProxy.cpp \
    UIProcess/WebGeolocationProvider.cpp \
    UIProcess/WebHistoryClient.cpp \
    UIProcess/WebIconDatabase.cpp \
    UIProcess/WebIconDatabaseClient.cpp \
    UIProcess/WebInspectorProxy.cpp \
    UIProcess/WebKeyValueStorageManagerProxy.cpp \
    UIProcess/WebLoaderClient.cpp \
    UIProcess/WebMediaCacheManagerProxy.cpp \
    UIProcess/WebNavigationData.cpp \
    UIProcess/WebOpenPanelResultListenerProxy.cpp \
    UIProcess/WebPageContextMenuClient.cpp \
    UIProcess/WebPageGroup.cpp \
    UIProcess/WebPageProxy.cpp \
    UIProcess/WebPolicyClient.cpp \
    UIProcess/WebPreferences.cpp \
    UIProcess/WebProcessProxy.cpp \
    UIProcess/WebResourceCacheManagerProxy.cpp \
    UIProcess/WebResourceLoadClient.cpp \
    UIProcess/WebUIClient.cpp \
    UIProcess/qt/ChunkedUpdateDrawingAreaProxyQt.cpp \
    UIProcess/qt/TiledDrawingAreaProxyQt.cpp \
    UIProcess/qt/TiledDrawingAreaTileQt.cpp \
    UIProcess/qt/TextCheckerQt.cpp \
    UIProcess/qt/WebContextMenuProxyQt.cpp \
    UIProcess/qt/WebContextQt.cpp \
    UIProcess/qt/WebInspectorProxyQt.cpp \
    UIProcess/qt/WebPageProxyQt.cpp \
    UIProcess/qt/WebPopupMenuProxyQt.cpp \
    UIProcess/qt/WebPreferencesQt.cpp \
    WebProcess/ApplicationCache/WebApplicationCacheManager.cpp \
    WebProcess/Authentication/AuthenticationManager.cpp \
    WebProcess/Cookies/WebCookieManager.cpp \
    WebProcess/Cookies/qt/WebCookieManagerQt.cpp \
    WebProcess/Downloads/Download.cpp \
    WebProcess/Downloads/DownloadManager.cpp \
    WebProcess/Downloads/qt/DownloadQt.cpp \
    WebProcess/FullScreen/WebFullScreenManager.cpp \
    WebProcess/Geolocation/GeolocationPermissionRequestManager.cpp \
    WebProcess/Geolocation/WebGeolocationManager.cpp \
    WebProcess/IconDatabase/WebIconDatabaseProxy.cpp \
    WebProcess/InjectedBundle/DOM/InjectedBundleNodeHandle.cpp \
    WebProcess/InjectedBundle/DOM/InjectedBundleRangeHandle.cpp \
    WebProcess/InjectedBundle/InjectedBundle.cpp \
    WebProcess/InjectedBundle/InjectedBundleBackForwardList.cpp \
    WebProcess/InjectedBundle/InjectedBundleBackForwardListItem.cpp \
    WebProcess/InjectedBundle/InjectedBundleClient.cpp \
    WebProcess/InjectedBundle/InjectedBundleHitTestResult.cpp \    
    WebProcess/InjectedBundle/InjectedBundleNavigationAction.cpp \
    WebProcess/InjectedBundle/InjectedBundlePageContextMenuClient.cpp \
    WebProcess/InjectedBundle/InjectedBundlePageEditorClient.cpp \
    WebProcess/InjectedBundle/InjectedBundlePageFormClient.cpp \
    WebProcess/InjectedBundle/InjectedBundlePageLoaderClient.cpp \
    WebProcess/InjectedBundle/InjectedBundlePagePolicyClient.cpp \
    WebProcess/InjectedBundle/InjectedBundlePageResourceLoadClient.cpp \
    WebProcess/InjectedBundle/InjectedBundlePageUIClient.cpp \
    WebProcess/InjectedBundle/InjectedBundleScriptWorld.cpp \
    WebProcess/InjectedBundle/qt/InjectedBundleQt.cpp \
    WebProcess/KeyValueStorage/WebKeyValueStorageManager.cpp \
    WebProcess/MediaCache/WebMediaCacheManager.cpp \
    WebProcess/ResourceCache/WebResourceCacheManager.cpp \
    WebProcess/Plugins/Netscape/JSNPMethod.cpp \
    WebProcess/Plugins/Netscape/JSNPObject.cpp \
    WebProcess/Plugins/Netscape/NPJSObject.cpp \
    WebProcess/Plugins/Netscape/NPRuntimeObjectMap.cpp \
    WebProcess/Plugins/Netscape/NPRuntimeUtilities.cpp \
    WebProcess/Plugins/Netscape/NetscapeBrowserFuncs.cpp \
    WebProcess/Plugins/Netscape/NetscapePlugin.cpp \
    WebProcess/Plugins/Netscape/NetscapePluginNone.cpp \
    WebProcess/Plugins/Netscape/NetscapePluginStream.cpp \
    WebProcess/Plugins/Netscape/x11/NetscapePluginX11.cpp \
    WebProcess/Plugins/Netscape/qt/PluginProxyQt.cpp \
    WebProcess/Plugins/Plugin.cpp \
    WebProcess/Plugins/PluginView.cpp \
    WebProcess/Plugins/PluginProxy.cpp \
    WebProcess/Plugins/PluginProcessConnection.cpp \
    WebProcess/Plugins/PluginProcessConnectionManager.cpp \
    WebProcess/WebCoreSupport/WebChromeClient.cpp \
    WebProcess/WebCoreSupport/WebContextMenuClient.cpp \
    WebProcess/WebCoreSupport/WebDatabaseManager.cpp \
    WebProcess/WebCoreSupport/WebDragClient.cpp \
    WebProcess/WebCoreSupport/WebEditorClient.cpp \
    WebProcess/WebCoreSupport/WebFrameLoaderClient.cpp \
    WebProcess/WebCoreSupport/WebGeolocationClient.cpp \
    WebProcess/WebCoreSupport/WebInspectorClient.cpp \
    WebProcess/WebCoreSupport/WebInspectorFrontendClient.cpp \
    WebProcess/WebCoreSupport/WebPlatformStrategies.cpp \
    WebProcess/WebCoreSupport/WebPopupMenu.cpp \
    WebProcess/WebCoreSupport/WebSearchPopupMenu.cpp \
    WebProcess/WebCoreSupport/qt/WebContextMenuClientQt.cpp \
    WebProcess/WebCoreSupport/qt/WebErrorsQt.cpp \
    WebProcess/WebCoreSupport/qt/WebFrameNetworkingContext.cpp \
    WebProcess/WebCoreSupport/qt/WebPopupMenuQt.cpp \
    WebProcess/WebPage/ChunkedUpdateDrawingArea.cpp \
    WebProcess/WebPage/DecoderAdapter.cpp \
    WebProcess/WebPage/DrawingArea.cpp \
    WebProcess/WebPage/DrawingAreaImpl.cpp \
    WebProcess/WebPage/EncoderAdapter.cpp \
    WebProcess/WebPage/FindController.cpp \
    WebProcess/WebPage/LayerTreeHost.cpp \
    WebProcess/WebPage/PageOverlay.cpp \
    WebProcess/WebPage/TiledDrawingArea.cpp \
    WebProcess/WebPage/WebBackForwardListProxy.cpp \
    WebProcess/WebPage/WebContextMenu.cpp \
    WebProcess/WebPage/WebEditCommand.cpp \
    WebProcess/WebPage/WebFrame.cpp \
    WebProcess/WebPage/WebInspector.cpp \
    WebProcess/WebPage/WebOpenPanelResultListener.cpp \
    WebProcess/WebPage/WebPage.cpp \
    WebProcess/WebPage/WebPageGroupProxy.cpp \
    WebProcess/WebPage/qt/WebInspectorQt.cpp \
    WebProcess/WebPage/qt/ChunkedUpdateDrawingAreaQt.cpp \
    WebProcess/WebPage/qt/TiledDrawingAreaQt.cpp \
    WebProcess/WebPage/qt/WebPageQt.cpp \
    WebProcess/WebProcess.cpp \
    WebProcess/qt/WebProcessMainQt.cpp \
    WebProcess/qt/WebProcessQt.cpp \
    $$WEBKIT2_GENERATED_SOURCES

