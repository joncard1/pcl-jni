#include <com_jackflashtech_pcl_search_impl_KdTreePointXYZ.h>
#include <pcl/point_types.h>
#include <pcl/search/kdtree.h>

JNIEXPORT jlong JNICALL Java_com_jackflashtech_pcl_search_impl_KdTreePointXYZ_createKdTreePointXYZ (JNIEnv *env, jobject object) {
	pcl::search::KdTree<pcl::PointXYZ>::Ptr *new_tree = new pcl::search::KdTree<pcl::PointXYZ>::Ptr (new pcl::search::KdTree<pcl::PointXYZ>);

	return (jlong)new_tree;
}
