#include <com_jackflashtech_pcl_impl_PointCloudNormalImpl.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_createPointCloud (JNIEnv *env, jobject object, jint height, jint width, jboolean is_dense) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_new_cloud = new pcl::PointCloud<pcl::Normal>::Ptr (new pcl::PointCloud<pcl::Normal>);
	(*p_new_cloud)->height = height;
	(*p_new_cloud)->width = width;
	(*p_new_cloud)->is_dense = is_dense;

	jclass cls = env->FindClass("com/jackflashtech/pcl/impl/NormalsList");
	jmethodID methodID = env->GetMethodID(cls, "<init>", "(J)V");
	jvalue args[1];
	args[0].j = (jlong)&((*p_new_cloud)->points);
	std::cout << "New Handle: " << args[0].j << "\n";
	jobject a = env->NewObjectA(cls, methodID, args);

	jfieldID l_pointsId = env->GetFieldID( env->GetObjectClass( object ), "points", "Ljava/util/List;" );
	env->SetObjectField(object, l_pointsId, a);

	return (jlong)p_new_cloud;
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_getHeight (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	return (*p_cloud)->height;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_setHeight (JNIEnv *env, jobject object, jint height, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	(*p_cloud)->height = height;
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_getWidth (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	return (*p_cloud)->width;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_setWidth (JNIEnv *env, jobject object, jint width, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	(*p_cloud)->width = width;
}

JNIEXPORT jboolean JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_isDense (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	return (*p_cloud)->is_dense;
}


JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_setIsDense (JNIEnv *env, jobject object, jboolean is_dense, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	(*p_cloud)->is_dense = is_dense;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_resize (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::Normal>::Ptr *p_cloud = (pcl::PointCloud<pcl::Normal>::Ptr *)handle;

	(*p_cloud)->points.resize((*p_cloud)->height * (*p_cloud)->width);
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointCloudNormalImpl_finalize (JNIEnv *env, jobject object, jlong handle) {
	pcl::PointCloud<pcl::PointNormal>::Ptr *p_cloud = (pcl::PointCloud<pcl::PointNormal>::Ptr *)handle;

	delete p_cloud;
}
