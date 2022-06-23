/*
 * Copyright (c) 2022 Pavel I. Kryukov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef OSTAPBENDER_COMBINATOR_H
#define OSTAPBENDER_COMBINATOR_H

#include <cstddef>

namespace combinator
{
    namespace details
    {
        template<typename T, std::size_t N, typename R, typename ... Args>
        struct f
        {
            using type = typename f<T, N - 1, R, R, Args...>::type;
        };

        template<typename T, typename R, typename ... Args>
        struct f<T, 0, R, Args...>
        {
            static T func(Args ...);
            using type = decltype(func);
        };
    }

    template<typename T, std::size_t N>
    using value = typename details::f<T, N, T>::type;

    template<typename T, std::size_t N>
    using ref = typename details::f<T, N, const T&>::type;
}

#endif // OSTAPBENDER_COMBINATOR_H
