#normal app
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-java-files-under, src)

LOCAL_PACKAGE_NAME := IPOD

# Builds against the public SDK if add,can't used hide api(include res)
#LOCAL_SDK_VERSION := current
#LOCAL_PROGUARD_ENABLED := disabled

include $(BUILD_PACKAGE)

# This finds and builds the test apk as well, so a single make does both.
include $(call all-makefiles-under,$(LOCAL_PATH))



#java library
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := name
LOCAL_SRC_FILES := $(call all-java-files-under, src)
include $(BUILD_STATIC_JAVA_LIBRARY)


#app whit java library note jar at libs
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_JAVA_LIBRARIES := libvolley libgoogle-gson
LOCAL_SRC_FILES := $(call all-java-files-under, src)
LOCAL_PACKAGE_NAME := Hacks
# Builds against the public SDK if add,can't used hide api(include res)
#LOCAL_SDK_VERSION := current
LOCAL_PROGUARD_FLAG_FILES := proguard.cfg
include $(BUILD_PACKAGE)

include $(CLEAR_VARS)

LOCAL_PREBUILT_STATIC_JAVA_LIBRARIES := libvolley:libs/volley.jar \
	libgoogle-gson:libs/google-gson.jar
include $(BUILD_MULTI_PREBUILT)
# This finds and builds the test apk as well, so a single make does both.
include $(call all-makefiles-under,$(LOCAL_PATH))


#third app
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE := name
LOCAL_MODULE_TAGS := optional
LOCAL_SRC_FILES := $(LOCAL_MODULE).apk
LOCAL_MODULE_CLASS := APPS
LOCAL_MODULE_SUFFIX := $(COMMON_ANDROID_PACKAGE_SUFFIX)
LOCAL_CERTIFICATE := PRESIGNED
#/system/app
LOCAL_MODULE_PATH := $(TARGET_OUT)/app

LOCAL_JNI_SHARED_LIBRARIES := libsoname
LOCAL_REQUIRED_MODULES := libsoname

include $(BUILD_PREBUILT)

#third so
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE := libsoname
LOCAL_SRC_FILES := lib/armeabi-v7a/$(LOCAL_MODULE).so
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_PATH := $(TARGET_OUT)/lib
LOCAL_MODULE_SUFFIX := .so
LOCAL_MULTILIB := 32
include $(BUILD_PREBUILT)

#mutil so
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS := optional
LOCAL_PREBUILT_LIBS := sdfapk.so sdffff.so
include $(BUILD_MULTI_PREBUILT)



#aar Android Archive
#创建libs/aaa.arr文件，修改Android.mk如下
LOCAL_AAPT_FLAGS += --auto-add-overlay \
				   --extra-packages aaa
LOCAL_STATIC_JAVA_AAR_LIBRARIES:=aaa

....
include $(CLEAR_VARS)
LOCAL_MODULE_TAGS:=optional
LOCAL_PREBUILT_STATIC_JAVA_LIBRARIES:=aaa:libs/aaa.aar
include $(BUILD_MULTI_PREBUILT)

