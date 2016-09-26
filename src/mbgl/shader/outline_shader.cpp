#include <mbgl/shader/outline_shader.hpp>
#include <mbgl/shader/outline.vertex.hpp>
#include <mbgl/shader/outline.fragment.hpp>
#include <mbgl/shader/plain_vertex.hpp>

namespace mbgl {

OutlineShader::OutlineShader(gl::Context& context, Defines defines)
    : Shader(shaders::outline::name,
             shaders::outline::vertex,
             shaders::outline::fragment,
             context, defines) {
}

void OutlineShader::bind(const gl::VertexBuffer<PlainVertex>&,
                       const int8_t* offset) {
    PlainVertex::bind(offset);
}

} // namespace mbgl
