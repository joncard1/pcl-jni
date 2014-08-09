#include <com_jackflashtech_pcl_features_impl_NormalEstimationImpl.h>
#include <pcl/pcl_base.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/impl/kdtree_flann.hpp>
#include <pcl/search/kdtree.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_createInstance (JNIEnv *env, jobject object) {
	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> *normal_estimation = new pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal>();

	return (jlong)normal_estimation;
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_setInputCloud (JNIEnv *env, jobject object, jobject input_cloud, jlong handle) {
	// TODO: Check that input_cloud is a PointCloud, or something.	
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( input_cloud ), "handle", "J" );
	pcl::PointCloud< pcl::PointXYZ >::Ptr *p_input_cloud = (pcl::PointCloud< pcl::PointXYZ >::Ptr *)env->GetLongField( input_cloud, l_handleId );

	((pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle)->setInputCloud((*p_input_cloud));
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_setSearchMethod (JNIEnv *env, jobject object, jobject tree, jlong handle) {
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( tree ), "handle", "J" );
	pcl::search::KdTree<pcl::PointXYZ> *tree_c = (pcl::search::KdTree< pcl::PointXYZ > *)env->GetLongField( tree, l_handleId );

	pcl::search::KdTree< pcl::PointXYZ >::Ptr tree_ptr (tree_c);
	((pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle)->setSearchMethod(tree_ptr);
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_setRadiusSearch (JNIEnv *env, jobject object, jdouble radius, jlong handle) {
	((pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle)->setRadiusSearch( radius );
}

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_features_impl_NormalEstimationImpl_compute (JNIEnv *env, jobject object, jobject output_cloud, jlong handle) {
	jfieldID l_handleId = env->GetFieldID( env->GetObjectClass( output_cloud ), "handle", "J" ); 
	pcl::PointCloud< pcl::Normal > *output_cloud_c = (pcl::PointCloud< pcl::Normal > *)env->GetLongField( output_cloud, l_handleId );

	pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *ne = (pcl::NormalEstimation< pcl::PointXYZ, pcl::Normal > *)handle;
	//pcl::PointCloud< pcl::Normal >::Ptr output_cloud_ptr (output_cloud_c);

	ne->compute( *output_cloud_c );

	std::cout << "First point: X: " << output_cloud_c->points[0].normal_x << ", Y: " << output_cloud_c->points[0].normal_y << ", Z: " << output_cloud_c->points[0].normal_z << "\n";
}
