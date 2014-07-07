#include <pcl/point_types.h>
#include <com_jackflashtech_pcl_impl_PointXYZImpl.h>

pcl::PointXYZ * PointXYZImpl_getPtr(JNIEnv *env, jobject object) {
     jfieldID l_handlerId = env->GetFieldID( env->GetObjectClass( object ), "handler", "J" );
     return (pcl::PointXYZ *)env->GetLongField(object, l_handlerId);
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_createPoint (JNIEnv *env, jobject object, jfloat x, jfloat y, jfloat z) {
    // Create object
    pcl::PointXYZ *new_point = new pcl::PointXYZ(x, y, z);

    // Store the pointer in the handler private variable 
    jfieldID l_handlerId = env->GetFieldID( env->GetObjectClass( object ), "handler", "J" );
    env->SetLongField(object, l_handlerId, (jlong)new_point);
}

JNIEXPORT jfloat JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_getX (JNIEnv *env, jobject object) {
     // Get object
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     // Return value
     return point->x;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_setX (JNIEnv *env, jobject object, jfloat x) {
     // Get object
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     // Set value
     point->x = x;
}

JNIEXPORT jfloat JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_getY (JNIEnv *env, jobject object) {
     // Get object
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     // Return Y
     return point->y;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_setY (JNIEnv *env, jobject object, jfloat y) {
     // Get object
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     // Set Y
     point->y = y;
}

JNIEXPORT jfloat JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_getZ (JNIEnv *env, jobject object) {
     // Get object
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     // Return z
     return point->z;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_setZ (JNIEnv *env, jobject object, jfloat z) {
     // Get object
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     // Set z
     point->z = z;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointXYZImpl_finalize (JNIEnv *env, jobject object) {
     // TODO: This is probably bad. See if we can use a smart pointer instead.
     pcl::PointXYZ *point = PointXYZImpl_getPtr(env, object);

     delete point;
}

