pipeline{
    agent any

    stages{

        stage('Checkout Code'){
            steps{
                checkout scm
            }

        }

        stage('Build and Test'){
            steps{
                sh '/opt/homebrew/bin/cmake -S . -B build'
                sh '/opt/homebrew/bin/cmake --build build -j 4'
                sh '/opt/homebrew/bin/ctest --test-dir build'
            }
        }

        stage('Documentation'){
            steps{
                sh '/opt/homebrew/bin/cmake --build build --targe doc'
            }
        }
    }

    post {
        always {
            sh 'rm -rf build'
            sh 'rm -rf doc'
        }
    }
}