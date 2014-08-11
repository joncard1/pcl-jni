#include <com_jackflashtech_pcl_features_impl_NormalEstimationImpl.h>
#include <pcl/pcl_base.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/impl/kdtree_flann.hpp>
#include <pcl/search/kdtree.h>

pcl::PointCloud< pcl::PointXYZ >::Ptr *g_input_cloud;

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_createInstance (JNIEnv *env, jobject object) {
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> *normal_estimation = new pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal>();

	return (jlong)normal_estimation;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_setInputCloud (JNIEnv *env, jobject object, jobject input_cloud, jlong handle) {
	// TODO: Check that input_cloud is a PointCloud, or something.	
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( input_cloud ), "handle", "J" );
	pcl::PointCloud< pcl::PointXYZ >::Ptr *p_input_cloud = (pcl::PointCloud< pcl::PointXYZ >::Ptr *)env->GetLongField( input_cloud, l_handleId );
	g_input_cloud = p_input_cloud;

	((pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle)->setInputCloud((*p_input_cloud));
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_setSearchMethod (JNIEnv *env, jobject object, jobject tree, jlong handle) {
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( tree ), "handle", "J" );
	pcl::search::KdTree<pcl::PointXYZ>::Ptr *p_tree = (pcl::search::KdTree< pcl::PointXYZ >::Ptr *)env->GetLongField( tree, l_handleId );

	((pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle)->setSearchMethod(*p_tree);
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_setRadiusSearch (JNIEnv *env, jobject object, jdouble radius, jlong handle) {
	((pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle)->setRadiusSearch( radius );
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_compute (JNIEnv *env, jobject object, jobject output_cloud, jlong handle) {
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( output_cloud ), "handle", "J" ); 
	pcl::PointCloud< pcl::Normal >::Ptr *p_output_cloud = (pcl::PointCloud< pcl::Normal >::Ptr *)env->GetLongField( output_cloud, l_handleId );

	pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *ne = (pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle;

	ne->compute( *(*p_output_cloud) );
}
