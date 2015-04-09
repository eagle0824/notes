#normal app
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES := $(call all-java-files-under, src)

LOCAL_PACKAGE_NAME := IPOD

# Builds against the public SDK if add,can't used hide api(include res)
#LOCAL_SDK_VERSION := current

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
