#include <iostream>
#include <com_jackflashtech_pcl_impl_NormalImpl.h>
#include <pcl/point_types.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_createNormal (JNIEnv *env, jobject object, jfloat x, jfloat y, jfloat z) {

	try {
		pcl::Normal *new_normal = new pcl::Normal();
		new_normal->normal_x = x;
		new_normal->normal_y = y;
		new_normal->normal_z = z;

		return (jlong)new_normal;
	} catch (std::bad_alloc& ba) {
		char *exClassName = "com/jackflashtech/pcl/PclException";
		jclass exClass = env->FindClass( exClassName );
		if( exClass == NULL ) {
			exClass = env->FindClass( "java/lang/NoClassDefFoundError" );
			return env->ThrowNew( exClass, "Could not find com.jackflashtech.pcl.PclException" );
		}

		return env->ThrowNew( exClass, "Bad allocation creating a NormalImpl.");
	}
}

JNIEXPORT jfloat JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_getX (JNIEnv *env, jobject object, jlong handle) {
	pcl::Normal *normal = (pcl::Normal *)handle;
	
	std::cout << "In Get X: " << normal->normal_x << "\n";
	return normal->normal_x;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_setX (JNIEnv *env, jobject object, jfloat x, jlong handle) {
	pcl::Normal *normal = (pcl::Normal *)handle;

	normal->normal_x = x;
}

JNIEXPORT jfloat JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_getY (JNIEnv *env, jobject object, jlong handle) {
	pcl::Normal *normal = (pcl::Normal *)handle;

	return normal->normal_y;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_setY (JNIEnv *env, jobject object, jfloat y, jlong handle) {
	pcl::Normal *normal = (pcl::Normal *)handle;

	normal->normal_y = y;
}

JNIEXPORT jfloat JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_getZ (JNIEnv *env, jobject object, jlong handle) {
	pcl::Normal *normal = (pcl::Normal *)handle;

	return normal->normal_z;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_setZ (JNIEnv *env, jobject object, jfloat z, jlong handle) {
	pcl::Normal *normal = (pcl::Normal *)handle;

	normal->normal_z = z;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_NormalImpl_finalize (JNIEnv *env, jobject object, jlong handle) {
     // TODO: This is probably bad. See if we can use a smart pointer instead.
     pcl::Normal *normal = (pcl::Normal *)handle;

    delete normal;
} 
