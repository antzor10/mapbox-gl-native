#include <mbgl/gl/context.hpp>
#include <mbgl/gl/gl.hpp>
#include <mbgl/gl/vertex_array.hpp>
#include <mbgl/util/traits.hpp>

namespace mbgl {
namespace gl {

static_assert(std::is_same<ProgramID, GLuint>::value, "OpenGL type mismatch");
static_assert(std::is_same<ShaderID, GLuint>::value, "OpenGL type mismatch");
static_assert(std::is_same<BufferID, GLuint>::value, "OpenGL type mismatch");
static_assert(std::is_same<TextureID, GLuint>::value, "OpenGL type mismatch");
static_assert(std::is_same<VertexArrayID, GLuint>::value, "OpenGL type mismatch");
static_assert(std::is_same<FramebufferID, GLuint>::value, "OpenGL type mismatch");
static_assert(std::is_same<RenderbufferID, GLuint>::value, "OpenGL type mismatch");

static_assert(std::is_same<StencilValue, GLint>::value, "OpenGL type mismatch");
static_assert(std::is_same<StencilMaskValue, GLuint>::value, "OpenGL type mismatch");

static_assert(underlying_type(StencilTestFunction::Never) == GL_NEVER, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::Less) == GL_LESS, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::Equal) == GL_EQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::LessEqual) == GL_LEQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::Greater) == GL_GREATER, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::NotEqual) == GL_NOTEQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::GreaterEqual) == GL_GEQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestFunction::Always) == GL_ALWAYS, "OpenGL enum mismatch");

static_assert(underlying_type(StencilTestOperation::Keep) == GL_KEEP, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::Zero) == GL_ZERO, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::Replace) == GL_REPLACE, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::Increment) == GL_INCR, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::IncrementWrap) == GL_INCR_WRAP, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::Decrement) == GL_DECR, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::DecrementWrap) == GL_DECR_WRAP, "OpenGL enum mismatch");
static_assert(underlying_type(StencilTestOperation::Invert) == GL_INVERT, "OpenGL enum mismatch");

static_assert(underlying_type(DepthTestFunction::Never) == GL_NEVER, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::Less) == GL_LESS, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::Equal) == GL_EQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::LessEqual) == GL_LEQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::Greater) == GL_GREATER, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::NotEqual) == GL_NOTEQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::GreaterEqual) == GL_GEQUAL, "OpenGL enum mismatch");
static_assert(underlying_type(DepthTestFunction::Always) == GL_ALWAYS, "OpenGL enum mismatch");

static_assert(underlying_type(BlendSourceFactor::Zero) == GL_ZERO, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::One) == GL_ONE, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::SrcColor) == GL_SRC_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::OneMinusSrcColor) == GL_ONE_MINUS_SRC_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::DstColor) == GL_DST_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::OneMinusDstColor) == GL_ONE_MINUS_DST_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::SrcAlpha) == GL_SRC_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::OneMinusSrcAlpha) == GL_ONE_MINUS_SRC_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::DstAlpha) == GL_DST_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::OneMinusDstAlpha) == GL_ONE_MINUS_DST_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::ConstantColor) == GL_CONSTANT_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::OneMinusConstantColor) == GL_ONE_MINUS_CONSTANT_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::ConstantAlpha) == GL_CONSTANT_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::OneMinusConstantAlpha) == GL_ONE_MINUS_CONSTANT_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendSourceFactor::SrcAlphaSaturate) == GL_SRC_ALPHA_SATURATE, "OpenGL enum mismatch");

static_assert(underlying_type(BlendDestinationFactor::Zero) == GL_ZERO, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::One) == GL_ONE, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::SrcColor) == GL_SRC_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::OneMinusSrcColor) == GL_ONE_MINUS_SRC_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::DstColor) == GL_DST_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::OneMinusDstColor) == GL_ONE_MINUS_DST_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::SrcAlpha) == GL_SRC_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::OneMinusSrcAlpha) == GL_ONE_MINUS_SRC_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::DstAlpha) == GL_DST_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::OneMinusDstAlpha) == GL_ONE_MINUS_DST_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::ConstantColor) == GL_CONSTANT_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::OneMinusConstantColor) == GL_ONE_MINUS_CONSTANT_COLOR, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::ConstantAlpha) == GL_CONSTANT_ALPHA, "OpenGL enum mismatch");
static_assert(underlying_type(BlendDestinationFactor::OneMinusConstantAlpha) == GL_ONE_MINUS_CONSTANT_ALPHA, "OpenGL enum mismatch");

Context::~Context() {
    reset();
}

UniqueProgram Context::createProgram() {
    return UniqueProgram{ MBGL_CHECK_ERROR(glCreateProgram()), { this } };
}

UniqueShader Context::createVertexShader() {
    return UniqueShader{ MBGL_CHECK_ERROR(glCreateShader(GL_VERTEX_SHADER)), { this } };
}

UniqueShader Context::createFragmentShader() {
    return UniqueShader{ MBGL_CHECK_ERROR(glCreateShader(GL_FRAGMENT_SHADER)), { this } };
}

UniqueBuffer Context::createBuffer() {
    BufferID id = 0;
    MBGL_CHECK_ERROR(glGenBuffers(1, &id));
    return UniqueBuffer{ std::move(id), { this } };
}

UniqueTexture Context::createTexture() {
    if (pooledTextures.empty()) {
        pooledTextures.resize(TextureMax);
        MBGL_CHECK_ERROR(glGenTextures(TextureMax, pooledTextures.data()));
    }

    TextureID id = pooledTextures.back();
    pooledTextures.pop_back();
    return UniqueTexture{ std::move(id), { this } };
}

UniqueVertexArray Context::createVertexArray() {
    VertexArrayID id = 0;
    MBGL_CHECK_ERROR(gl::GenVertexArrays(1, &id));
    return UniqueVertexArray{ std::move(id), { this } };
}

UniqueFramebuffer Context::createFramebuffer() {
    FramebufferID id = 0;
    MBGL_CHECK_ERROR(glGenFramebuffers(1, &id));
    return UniqueFramebuffer{ std::move(id), { this } };
}

void Context::uploadBuffer(BufferType type, size_t size, void* data) {
    MBGL_CHECK_ERROR(glBufferData(static_cast<GLenum>(type), size, data, GL_STATIC_DRAW));
}

void Context::reset() {
    std::copy(pooledTextures.begin(), pooledTextures.end(), std::back_inserter(abandonedTextures));
    pooledTextures.resize(0);
    performCleanup();
}

UniqueBuffer Context::createVertexBufferWithData(const void* data, std::size_t size) {
    UniqueBuffer result = createBuffer();
    vertexBuffer = result;
    MBGL_CHECK_ERROR(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
    return result;
}

namespace {

template <typename Fn>
void applyStateFunction(Context& context, Fn&& fn) {
    fn(context.stencilFunc);
    fn(context.stencilMask);
    fn(context.stencilTest);
    fn(context.stencilOp);
    fn(context.depthRange);
    fn(context.depthMask);
    fn(context.depthTest);
    fn(context.depthFunc);
    fn(context.blend);
    fn(context.blendFunc);
    fn(context.blendColor);
    fn(context.colorMask);
    fn(context.program);
    fn(context.lineWidth);
    fn(context.activeTexture);
    fn(context.bindFramebuffer);
    fn(context.viewport);
#if not MBGL_USE_GLES2
    fn(context.pixelZoom);
    fn(context.rasterPos);
#endif // MBGL_USE_GLES2
    for (auto& tex : context.texture) {
        fn(tex);
    }
    fn(context.vertexBuffer);
    fn(context.elementBuffer);
    fn(context.vertexArrayObject);
}

} // namespace

void Context::resetState() {
    applyStateFunction(*this, [](auto& state) { state.reset(); });
}

void Context::setDirtyState() {
    applyStateFunction(*this, [](auto& state) { state.setDirty(); });
}

void Context::clear(optional<mbgl::Color> color,
                    optional<float> depth,
                    optional<int32_t> stencil) {
    GLbitfield mask = 0;

    if (color) {
        mask |= GL_COLOR_BUFFER_BIT;
        MBGL_CHECK_ERROR(glClearColor(color->r, color->g, color->b, color->a));
    }

    if (depth) {
        mask |= GL_DEPTH_BUFFER_BIT;
        MBGL_CHECK_ERROR(glClearDepth(*depth));
    }

    if (stencil) {
        mask |= GL_STENCIL_BUFFER_BIT;
        MBGL_CHECK_ERROR(glClearStencil(*stencil));
    }

    MBGL_CHECK_ERROR(glClear(mask));
}

// Depth

static void prepare(const Depth& depth) {
    if (depth.test == Depth::Always && !depth.mask) {
        MBGL_CHECK_ERROR(glDisable(GL_DEPTH_TEST));
    } else {
        MBGL_CHECK_ERROR(glEnable(GL_DEPTH_TEST));
        MBGL_CHECK_ERROR(glDepthFunc(depth.test));
        MBGL_CHECK_ERROR(glDepthMask(depth.mask));
        MBGL_CHECK_ERROR(glDepthRange(depth.range.min, depth.range.max));
    }
}

// Stencil

template <GLenum F>
static void prepare(const Stencil::SimpleTest<F>&, GLint ref) {
    MBGL_CHECK_ERROR(glStencilFunc(F, ref, 0));
}

template <GLenum F>
static void prepare(const Stencil::MaskedTest<F>& test, GLint ref) {
    MBGL_CHECK_ERROR(glStencilFunc(F, ref, test.mask));
}

static void prepare(const Stencil& stencil) {
    if (stencil.test.is<Stencil::Always>() && !stencil.mask) {
        MBGL_CHECK_ERROR(glDisable(GL_STENCIL_TEST));
    } else {
        MBGL_CHECK_ERROR(glEnable(GL_STENCIL_TEST));
        apply_visitor([&] (const auto& t) { prepare(t, stencil.ref); }, stencil.test);
        MBGL_CHECK_ERROR(glStencilMask(stencil.mask));
        MBGL_CHECK_ERROR(glStencilOp(stencil.fail, stencil.depthFail, stencil.pass));
    }
}

// Color

static void prepare(const Color::Replace&) {
    assert(false); // unreachable
}

template <GLenum F>
static void prepare(const Color::ConstantBlend<F>&) {
    MBGL_CHECK_ERROR(glBlendEquation(F));
}

template <GLenum F>
static void prepare(const Color::LinearBlend<F>& function) {
    MBGL_CHECK_ERROR(glBlendEquation(F));
    MBGL_CHECK_ERROR(glBlendFunc(function.srcFactor, function.dstFactor));
}

static void prepare(const Color& color) {
    MBGL_CHECK_ERROR(glColorMask(color.mask.r,
                                 color.mask.g,
                                 color.mask.b,
                                 color.mask.a));

    if (color.blendFunction.is<Color::Replace>()) {
        MBGL_CHECK_ERROR(glDisable(GL_BLEND));
    } else {
        MBGL_CHECK_ERROR(glEnable(GL_BLEND));
        apply_visitor([] (const auto& f) { prepare(f); }, color.blendFunction);
        MBGL_CHECK_ERROR(glBlendColor(color.blendColor.r,
                                      color.blendColor.g,
                                      color.blendColor.b,
                                      color.blendColor.a));
    }
}

// Program

static void prepare(const UniformScalar<int32_t>& scalar, GLenum&) {
    MBGL_CHECK_ERROR(glUniform1i(scalar.location, scalar.value));
}

static void prepare(const UniformScalar<float>& scalar, GLenum&) {
    MBGL_CHECK_ERROR(glUniform1f(scalar.location, scalar.value));
}

static void prepare(const UniformVector<2, float>& vector, GLenum&) {
    MBGL_CHECK_ERROR(glUniform2f(vector.location, vector.value[0], vector.value[1]));
}

static void prepare(const UniformVector<3, float>& vector, GLenum&) {
    MBGL_CHECK_ERROR(glUniform3f(vector.location, vector.value[0], vector.value[1], vector.value[2]));
}

static void prepare(const UniformVector<4, float>& vector, GLenum&) {
    MBGL_CHECK_ERROR(glUniform4f(vector.location, vector.value[0], vector.value[1], vector.value[2], vector.value[3]));
}

static void prepare(const UniformMatrix<2>& matrix, GLenum&) {
    MBGL_CHECK_ERROR(glUniformMatrix2fv(matrix.location, 1, GL_FALSE, matrix.value.data()));
}

static void prepare(const UniformMatrix<3>& matrix, GLenum&) {
    MBGL_CHECK_ERROR(glUniformMatrix3fv(matrix.location, 1, GL_FALSE, matrix.value.data()));
}

static void prepare(const UniformMatrix<4>& matrix, GLenum&) {
    MBGL_CHECK_ERROR(glUniformMatrix4fv(matrix.location, 1, GL_FALSE, matrix.value.data()));
}

static void prepare(const UniformTexture2d& texture, GLenum& textureUnit) {
    MBGL_CHECK_ERROR(glActiveTexture(textureUnit));
    MBGL_CHECK_ERROR(glBindTexture(GL_TEXTURE_2D, texture.texture));
    MBGL_CHECK_ERROR(glUniform1i(texture.location, textureUnit));
    ++textureUnit;
}

static void prepare(const Program& program) {
    MBGL_CHECK_ERROR(glUseProgram(program.program));

    GLenum textureUnit = GL_TEXTURE0;
    for (const auto& uniform : program.uniforms) {
        apply_visitor([&] (const auto& u) { prepare(u, textureUnit); }, uniform);
    }
}

// Vertexes

template <typename T> struct AttributeType;

template <> struct AttributeType<int8_t>   : std::integral_constant<GLenum, GL_BYTE> {};
template <> struct AttributeType<uint8_t>  : std::integral_constant<GLenum, GL_UNSIGNED_BYTE> {};
template <> struct AttributeType<int16_t>  : std::integral_constant<GLenum, GL_SHORT> {};
template <> struct AttributeType<uint16_t> : std::integral_constant<GLenum, GL_UNSIGNED_SHORT> {};
template <> struct AttributeType<int32_t>  : std::integral_constant<GLenum, GL_INT> {};
template <> struct AttributeType<uint32_t> : std::integral_constant<GLenum, GL_UNSIGNED_INT> {};
template <> struct AttributeType<float>    : std::integral_constant<GLenum, GL_FLOAT> {};
template <> struct AttributeType<double>   : std::integral_constant<GLenum, GL_DOUBLE> {};

template <std::size_t N, class T>
static void prepare(const Vertexes& vertexes, const TypedVertexAttribute<N, T>& attr) {
    MBGL_CHECK_ERROR(glEnableVertexAttribArray(attr.location));
    MBGL_CHECK_ERROR(glVertexAttribPointer(attr.location,
                                           N,
                                           AttributeType<T>::value,
                                           GL_FALSE,
                                           attr.byteStride.value,
                                           attr.byteOffset + (vertexes.vertexSize * vertexes.vertexOffset)));
}

static void prepare(const Vertexes& vertexes) {
    MBGL_CHECK_ERROR(glBindBuffer(GL_ARRAY_BUFFER,
                                  vertexes.buffer));

    for (const auto& attribute : vertexes.attributes) {
        apply_visitor([&] (const auto& attr) { prepare(vertexes, attr); }, attribute);
    }
}

// Primitive

static GLenum prepare(const Points& points) {
    MBGL_CHECK_ERROR(glPointSize(points.pointSize));
    return GL_POINTS;
}

static GLenum prepare(const Lines& lines) {
    MBGL_CHECK_ERROR(glLineWidth(lines.lineWidth));
    return GL_LINES;
}

static GLenum prepare(const LineStrip& lineStrip) {
    MBGL_CHECK_ERROR(glLineWidth(lineStrip.lineWidth));
    return GL_LINE_STRIP;
}

static GLenum prepare(const Triangles&) {
    return GL_TRIANGLES;
}

static GLenum prepare(const TriangleStrip&) {
    return GL_TRIANGLE_STRIP;
}

static GLenum prepare(const Primitive& primitive) {
    return apply_visitor([&] (const auto& p) { return prepare(p); }, primitive);
}

// Draw

template <typename T> struct IndexType;

template <> struct IndexType<uint8_t>  : std::integral_constant<GLenum, GL_UNSIGNED_BYTE> {};
template <> struct IndexType<uint16_t> : std::integral_constant<GLenum, GL_UNSIGNED_SHORT> {};
template <> struct IndexType<uint32_t> : std::integral_constant<GLenum, GL_UNSIGNED_INT> {};

template <typename P, typename T>
static void draw(const Vertexes&,
                 const IndexBuffer<P, T>& slice,
                 const Primitive& primitive) {
    MBGL_CHECK_ERROR(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,
                                  slice.buffer));

    MBGL_CHECK_ERROR(glDrawElements(prepare(primitive),
                                    slice.indexCount.value,
                                    IndexType<T>::value,
                                    slice.byteOffset));
}

static void draw(const Vertexes& vertexes,
                 const Unindexed&,
                 const Primitive& primitive) {
    MBGL_CHECK_ERROR(glDrawArrays(prepare(primitive),
                                  vertexes.vertexOffset.value,
                                  vertexes.vertexCount.value));
}

void Context::draw(const Depth& depth,
                   const Stencil& stencil,
                   const Color& color,
                   const Program& program_,
                   const Vertexes& vertexes,
                   const Indexes& indexes,
                   const Primitive& primitive)
{
    prepare(depth);
    prepare(stencil);
    prepare(color);
    prepare(program_);
    prepare(vertexes);
    apply_visitor([&] (const auto& indexes_) { gl::draw(vertexes, indexes_, primitive); }, indexes);
}

void Context::performCleanup() {
    for (auto id : abandonedPrograms) {
        if (program == id) {
            program.setDirty();
        }
        MBGL_CHECK_ERROR(glDeleteProgram(id));
    }
    abandonedPrograms.clear();

    for (auto id : abandonedShaders) {
        MBGL_CHECK_ERROR(glDeleteShader(id));
    }
    abandonedShaders.clear();

    if (!abandonedBuffers.empty()) {
        for (const auto id : abandonedBuffers) {
            if (vertexBuffer == id) {
                vertexBuffer.setDirty();
            } else if (elementBuffer == id) {
                elementBuffer.setDirty();
            }
        }
        MBGL_CHECK_ERROR(glDeleteBuffers(int(abandonedBuffers.size()), abandonedBuffers.data()));
        abandonedBuffers.clear();
    }

    if (!abandonedTextures.empty()) {
        for (const auto id : abandonedTextures) {
            if (activeTexture == id) {
                activeTexture.setDirty();
            }
        }
        MBGL_CHECK_ERROR(glDeleteTextures(int(abandonedTextures.size()), abandonedTextures.data()));
        abandonedTextures.clear();
    }

    if (!abandonedVertexArrays.empty()) {
        for (const auto id : abandonedVertexArrays) {
            if (vertexArrayObject == id) {
                vertexArrayObject.setDirty();
            }
        }
        MBGL_CHECK_ERROR(gl::DeleteVertexArrays(int(abandonedVertexArrays.size()),
                                                abandonedVertexArrays.data()));
        abandonedVertexArrays.clear();
    }

    if (!abandonedFramebuffers.empty()) {
        for (const auto id : abandonedFramebuffers) {
            if (bindFramebuffer == id) {
                bindFramebuffer.setDirty();
            }
        }
        MBGL_CHECK_ERROR(
            glDeleteFramebuffers(int(abandonedFramebuffers.size()), abandonedFramebuffers.data()));
        abandonedFramebuffers.clear();
    }
}

} // namespace gl
} // namespace mbgl
