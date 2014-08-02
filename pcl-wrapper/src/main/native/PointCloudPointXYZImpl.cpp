#include <iostream>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <com_jackflashtech_pcl_impl_PointCloudPointXYZImpl.h>

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_getHeight(JNIEnv *env, jobject object, jlong handle) {
	// Get object
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	// Return value
	return cloud->height;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_setHeight(JNIEnv *env, jobject object, jint height, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	cloud->height = height;
	cloud->points.resize(cloud->height * cloud->width);
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_getWidth (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	return cloud->width;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_setWidth (JNIEnv *env, jobject object, jint width, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	cloud->width = width;
	cloud->points.resize(cloud->height * cloud->width);
}

JNIEXPORT jboolean JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_isDense (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	return cloud->is_dense;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_setIsDense (JNIEnv *env, jobject object, jboolean is_dense, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	cloud->is_dense = is_dense;
}

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_PointCloudPointXYZImpl_createPointCloud (JNIEnv *env, jobject object, jint height, jint width, jboolean is_dense) {
	pcl::PointCloud<pcl::PointXYZ> *new_cloud = new pcl::PointCloud<pcl::PointXYZ>();
	new_cloud->height = height;
	new_cloud->width = width;
	new_cloud->is_dense = is_dense;

	jclass cls = env->FindClass("com/jackflashtech/pcl/impl/PointsList");
	jmethodID methodID = env->GetMethodID(cls, "<init>", "(J)V");
	jvalue args[1] = {(jlong)&new_cloud->points};
	jobject a = env->NewObject(cls, methodID, args);

	jfieldID l_pointsId = env->GetFieldID( env->GetObjectClass( object ), "points", "Ljava/util/List;" );
	env->SetObjectField(object, l_pointsId, a);

	return (jlong)new_cloud;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudImpl_finalize (JNIEnv *, jobject, jlong handle) {
	pcl::PointCloud<pcl::PointXYZ> *cloud = (pcl::PointCloud<pcl::PointXYZ> *)handle;

	delete cloud;
}

