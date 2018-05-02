//
//  ARDeclarativeImageNode_JNI.cpp
//  ViroRenderer
//
//  Copyright © 2018 Viro Media. All rights reserved.
//

#include "ARDeclarativeImageNode_JNI.h"
#include "ARImageTarget_JNI.h"

#if VRO_PLATFORM_ANDROID
#define VRO_METHOD(return_type, method_name) \
  JNIEXPORT return_type JNICALL              \
      Java_com_viro_core_internal_ARDeclarativeImageNode_##method_name
#else
#define VRO_METHOD(return_type, method_name) \
    return_type ARDeclarativeImageNode_##method_name
#endif

extern "C" {

VRO_METHOD(VRO_REF(VROARDeclarativeImageNode), nativeCreateARImageTargetNode)(VRO_NO_ARGS) {
    std::shared_ptr<VROARDeclarativeImageNode> arImageNode = std::make_shared<VROARDeclarativeImageNode>();
    return ARDeclarativeImageNode::jptr(arImageNode);
}

VRO_METHOD(void, nativeSetARImageTarget)(VRO_ARGS
                                         VRO_REF(VROARDeclarativeImageNode) nativeARImageNode,
                                         VRO_REF(VROARImageTarget) nativeARImageTarget) {
    std::shared_ptr<VROARDeclarativeImageNode> arImageNode = ARDeclarativeImageNode::native(nativeARImageNode);
    std::shared_ptr<VROARImageTarget> arImageTarget = ARImageTarget::native(nativeARImageTarget);
    arImageNode->setImageTarget(arImageTarget);
}

} // extern "C"