#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <com_jackflashtech_pcl_impl_PointsList.h>

JNIEXPORT void JNICALL Java_com_jackflashtech_pcl_impl_PointsList_add (JNIEnv *env, jobject object, jlong handle, jint index, jobject element) {
	std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *points = (std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *)handle;

	// TODO: Check that the element is a PointXYZ;
	jfieldID l_handlerId = env->GetFieldID( env->GetObjectClass( object ), "handler", "J");
	pcl::PointXYZ *point = (pcl::PointXYZ *)env->GetLongField(object, l_handlerId);

	(*points)[index].x = point->x;
	(*points)[index].y = point->y;
	(*points)[index].z = point->z;
}

JNIEXPORT jint JNICALL Java_com_jackflashtech_pcl_impl_PointsList_size (JNIEnv *env, jobject object, jlong handle) {
	std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *points = (std::vector<pcl::PointXYZ, Eigen::aligned_allocator<pcl::PointXYZ> > *)handle;
	return points->size();
}
