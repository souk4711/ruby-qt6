#include "qsurface-rb.hpp"
#include <qsurface.h>

using namespace Rice;

Rice::Class rb_cQSurface;

void Init_qsurface(Rice::Module rb_mQt6QtGui)
{
    rb_cQSurface =
        // RubyQt6::QtGui::QSurface
        define_class_under<QSurface>(rb_mQt6QtGui, "QSurface")
            .define_method("_format", &QSurface::format)
            .define_method("_size", &QSurface::size)
            .define_method("_supports_open_gl?", &QSurface::supportsOpenGL)
            .define_method("_surface_class", &QSurface::surfaceClass)
            // .define_method("_surface_handle", &QSurface::surfaceHandle)
            .define_method("_surface_type", &QSurface::surfaceType);

    Enum<QSurface::SurfaceClass> rb_cQSurfaceSurfaceClass =
        // RubyQt6::QtGui::QSurface::SurfaceClass
        define_enum_under<QSurface::SurfaceClass>("SurfaceClass", rb_cQSurface)
            .define_value("Window", QSurface::SurfaceClass::Window)
            .define_value("Offscreen", QSurface::SurfaceClass::Offscreen);

    Enum<QSurface::SurfaceType> rb_cQSurfaceSurfaceType =
        // RubyQt6::QtGui::QSurface::SurfaceType
        define_enum_under<QSurface::SurfaceType>("SurfaceType", rb_cQSurface)
            .define_value("RasterSurface", QSurface::SurfaceType::RasterSurface)
            .define_value("OpenGLSurface", QSurface::SurfaceType::OpenGLSurface)
            .define_value("RasterGLSurface", QSurface::SurfaceType::RasterGLSurface)
            .define_value("OpenVGSurface", QSurface::SurfaceType::OpenVGSurface)
            .define_value("VulkanSurface", QSurface::SurfaceType::VulkanSurface)
            .define_value("MetalSurface", QSurface::SurfaceType::MetalSurface)
            .define_value("Direct3DSurface", QSurface::SurfaceType::Direct3DSurface);
}
