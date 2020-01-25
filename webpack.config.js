const path = require('path');

module.exports = {
    entry: ['./src/index.re'],
    output: {
        path: path.join(__dirname, '..', 'bundledOutputs'),
        filename: '[name].js',
        publicPath: './'
    },
    module: {
        rules: [
            // Set up Reason and OCaml files to use the loader
            { test: /\.(re|ml)$/, use: 'bs-loader' },
            {
                test: /\.css$/i,
                use: ['style-loader', 'css-loader?modules=true']
            },
            {
                test: /\.s[ac]ss$/i,
                use: [
                    // Creates `style` nodes from JS strings
                    'style-loader',
                    // Translates CSS into CommonJS
                    'css-loader?modules=true',
                    // Compiles Sass to CSS
                    'sass-loader'
                ]
            },
            {
                test: /.(ttf|otf|eot|svg|woff(2)?)(\?[a-z0-9]+)?$/,
                use: {
                    loader: 'url-loader',
                    options: {
                        // Limit at 50k. Above that it emits separate files
                        limit: 50000,
                        // Output below fonts directory
                        name: './src/fonts/[name].[ext]'
                    }
                }
            }
        ]
    },
    resolve: {
        // Add .re and .ml to the list of extensions webpack recognizes
        extensions: ['.re', '.ml', '.js']
    },
    devtool: 'inline-source-map',
    devServer: {
        hot: true,
        port: 8081,
        historyApiFallback: true,
        contentBase: './',
        publicPath: '/bundledOutputs/',
        watchOptions: {
            ignored: [/node_modules/, /bundledOutputs/]
        }
    }
};
