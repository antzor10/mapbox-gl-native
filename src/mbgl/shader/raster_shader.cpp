#include <mbgl/shader/raster_shader.hpp>
#include <mbgl/shader/raster.vertex.hpp>
#include <mbgl/shader/raster.fragment.hpp>
#include <mbgl/gl/gl.hpp>

namespace mbgl {

RasterShader::RasterShader(gl::Context& context, Defines defines)
    : Shader(shaders::raster::name,
             shaders::raster::vertex,
             shaders::raster::fragment,
             context, defines) {
}

void RasterShader::bind(int8_t* offset) {
    const GLint stride = 8;

    MBGL_CHECK_ERROR(glEnableVertexAttribArray(a_pos));
    MBGL_CHECK_ERROR(glVertexAttribPointer(a_pos, 2, GL_SHORT, false, stride, offset));

    MBGL_CHECK_ERROR(glEnableVertexAttribArray(a_texture_pos));
    MBGL_CHECK_ERROR(glVertexAttribPointer(a_texture_pos, 2, GL_SHORT, false, stride, offset + 4));
}

} // namespace mbgl
