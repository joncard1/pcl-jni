#include <com_jackflashtech_pcl_impl_PointCloudNormalImpl.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_createPointCloud (JNIEnv *env, jobject object, jint height, jint width, jboolean is_dense) {
	pcl::PointCloud<pcl::Normal> *new_cloud = new pcl::PointCloud<pcl::Normal>();
	new_cloud->height = height;
	new_cloud->width = width;
	new_cloud->is_dense = is_dense;

	return (jlong)new_cloud;
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_getHeight (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal> *cloud = (pcl::PointCloud<pcl::Normal> *)handle;

	return cloud->height;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_setHeight (JNIEnv *env, jobject object, jint height, jlong handle) {
	pcl::PointCloud<pcl::Normal> *cloud = (pcl::PointCloud<pcl::Normal> *)handle;

	cloud->height = height;
	cloud->points.resize(cloud->height * cloud->width);
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_getWidth (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal> *cloud = (pcl::PointCloud<pcl::Normal> *)handle;

	return cloud->width;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_setWidth (JNIEnv *env, jobject object, jint width, jlong handle) {
	pcl::PointCloud<pcl::Normal> *cloud = (pcl::PointCloud<pcl::Normal> *)handle;

	cloud->width = width;
	cloud->points.resize(cloud->height * cloud->width);
}

JNIEXPORT jboolean JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_isDense (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal> *cloud = (pcl::PointCloud<pcl::Normal> *)handle;

	return cloud->is_dense;
}


JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_setIsDense (JNIEnv *env, jobject object, jboolean is_dense, jlong handle) {
	pcl::PointCloud<pcl::Normal> *cloud = (pcl::PointCloud<pcl::Normal> *)handle;

	cloud->is_dense = is_dense;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_finalize (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointNormal> *cloud = (pcl::PointCloud<pcl::PointNormal> *)handle;

	delete cloud;
}
