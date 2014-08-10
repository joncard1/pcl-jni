#include <iostream>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <com_jackflashtech_pcl_impl_PointCloudPointXYZImpl.h>

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_getHeight(JNIEnv *env, jobject object, jlong handle) {
	// Get object
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;

	// Return value
	return (*p_cloud)->height;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_setHeight(JNIEnv *env, jobject object, jint height, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;
	(*p_cloud)->height = height;
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_getWidth (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;

	return (*p_cloud)->width;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_setWidth (JNIEnv *env, jobject object, jint width, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;

	(*p_cloud)->width = width;
}

JNIEXPORT jboolean JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_isDense (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;

	return (*p_cloud)->is_dense;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_setIsDense (JNIEnv *env, jobject object, jboolean is_dense, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;

	(*p_cloud)->is_dense = is_dense;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_resize (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;
	(*p_cloud)->resize((*p_cloud)->height * (*p_cloud)->width);
}

/**
 * I use a pcl::PointCloud<pcl::PointXYZ>::Ptr because there are some methods in the PCL that take that as an argument, and creating a ::Ptr locally causes the object to be deleted.
 */
JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_createPointCloud (JNIEnv *env, jobject object, jint height, jint width, jboolean is_dense) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_new_cloud = new pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
	(*p_new_cloud)->height = height;
	(*p_new_cloud)->width = width;
	(*p_new_cloud)->is_dense = is_dense;

	jclass cls = env->FindClass("com/jackflashtech/pcl/impl/PointsList");
	jmethodID methodID = env->GetMethodID(cls, "<init>", "(J)V");
	jvalue args[1];
	args[0].j = (jlong)&((*p_new_cloud)->points);
	jobject a = env->NewObjectA(cls, methodID, args);

	jfieldID l_pointsId = env->GetFieldID( env->GetObjectClass( object ), "points", "Ljava/util/List;" );
	env->SetObjectField(object, l_pointsId, a);

	return (jlong)p_new_cloud;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudImpl_finalize (JNIEnv *, jobject, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointXYZ>::Ptr *)handle;

	delete p_cloud;
}

